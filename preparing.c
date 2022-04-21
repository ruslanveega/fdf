/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 02:38:00 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/21 02:43:50 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_y(fdf *data, int **z0, int **z1)
{
	float	previous_x;

	previous_x = data->x0;
	data->x0 = previous_x * cos(data->rot_y) + **z0 * sin(data->rot_y);
	**z0 = -previous_x * sin(data->rot_y) + **z0 * cos(data->rot_y);
	previous_x = data->x1;
	data->x1 = previous_x * cos(data->rot_y) + **z1 * sin(data->rot_y);
	**z1 = -previous_x * sin(data->rot_y) + **z1 * cos(data->rot_y);
}

void	rotate_x(fdf *data, int **z0, int **z1)
{
	float	previous_y;

	previous_y = data->y0;
	data->y0 = previous_y * cos(data->rot_x) + **z0 * sin(data->rot_x);
	**z0 = -previous_y * sin(data->rot_x) + **z0 * cos(data->rot_x);
	previous_y = data->y1;
	data->y1 = previous_y * cos(data->rot_x) + **z1 * sin(data->rot_x);
	**z1 = -previous_y * sin(data->rot_x) + **z1 * cos(data->rot_x);
}

void	rotate_z(fdf *data)
{
	float	previous_x;
	float	previous_y;

	previous_x = data->x0;
	previous_y = data->y0;
	data->x0 = previous_x * cos(data->rot_z) - previous_y * sin(data->rot_z);
	data->y0 = previous_x * sin(data->rot_z) + previous_y * cos(data->rot_z);
	previous_x = data->x1;
	previous_y = data->y1;
	data->x1 = previous_x * cos(data->rot_z) - previous_y * sin(data->rot_z);
	data->y1 = previous_x * sin(data->rot_z) + previous_y * cos(data->rot_z);
}

void	data_prepare(int *z1, int *z0, fdf *data)
{
	*z0 *= data->shift_z;
	*z1 *= data->shift_z;
	data->x0 *= data->scale;
	data->y0 *= data->scale;
	data->x1 *= data->scale;
	data->y1 *= data->scale;
	rotate_y(data, &z0, &z1);
	rotate_x(data, &z0, &z1);
	rotate_z(data);
	data->y0 += data->shift_y;
	data->x0 += data->shift_x;
	data->y1 += data->shift_y;
	data->x1 += data->shift_x;
}

void	color(int z0, int z1, fdf *data)
{
	if (z0 || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}
