/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:36:52 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/16 01:23:11 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_mod(float x, float y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return ((int)x);
	return ((int)y);
}

void	draw_map(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				brosenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				brosenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}


void	brosenham(float x0, float y0, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z0;
	int		z1;

	z0 = data->z_matrix[(int)y0][(int)x0];
	z1 = data->z_matrix[(int)y1][(int)x1];
	z0 *= data->shift_z;
	z1 *= data->shift_z;
	x1 *= data->scale;
	x0 *= data->scale;
	y0 *= data->scale;
	y1 *= data->scale;
	x0 = (x0 - y0) * cos(data->alpha);
	y0 = (x0 + y0) * sin(data->alpha) - z0;
	x1 = (x1 - y1) * cos(data->alpha);
	y1 = (x1 + y1) * sin(data->alpha) - z1;
	y0 += data->shift_y;
	y1 += data->shift_y;
	x0 += data->shift_x;
	x1 += data->shift_x;
	x_step = x1 - x0;
	y_step = y1 - y0;
	data->color = (z0 || z1) ? 0xe80c0c : 0xffffff;
	max = max_mod(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x1 - x0) || (int)(y1 - y0))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color);
		y0 += y_step;
		x0 += x_step;
	}
}
