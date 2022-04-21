/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:36:52 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/21 02:58:47 by fcassand         ###   ########.fr       */
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

void	for_bros(int x, int y, fdf *data)
{
	if (x < data->width - 1)
	{
		data->x0 = x;
		data->y0 = y;
		data->x1 = x + 1;
		data->y1 = y;
		brosenham(data);
	}
	if (y < data->height - 1)
	{
		data->x0 = x;
		data->y0 = y;
		data->x1 = x;
		data->y1 = y + 1;
		brosenham(data);
	}
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
			for_bros(x, y, data);
			x++;
		}
		y++;
	}
}

void	brosenham(fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z0;
	int		z1;

	z0 = data->z_matrix[(int)(data->y0)][(int)(data->x0)];
	z1 = data->z_matrix[(int)(data->y1)][(int)(data->x1)];
	color(z0, z1, data);
	data_prepare(&z1, &z0, data);
	x_step = data->x1 - data->x0;
	y_step = data->y1 - data->y0;
	max = max_mod(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(data->x1 - data->x0) || (int)(data->y1 - data->y0))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		data->x0, data->y0, data->color);
		data->y0 += y_step;
		data->x0 += x_step;
	}
}
