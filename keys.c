/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:13:31 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/21 03:14:03 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_scale(int key, fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 91)
		data->shift_z += 1;
	if (key == 84)
		data->shift_z -= 1;
	if (key == 69)
		data->scale += 1;
	if (key == 78)
		data->scale -= 1;
}

void	projection(int key, fdf *data)
{
	if (key == 6)
	{
		data->rot_z = 0.00;
		data->rot_y = 0.00;
		data->rot_x = 0.00;
	}
	if (key == 7)
	{
		data->rot_z = 0.00;
		data->rot_y = 0.00;
		data->rot_x = -1.57;
	}
	if (key == 16)
	{
		data->rot_z = 0.00;
		data->rot_y = 1.57;
		data->rot_x = 0.00;
	}
}

void	camera(int key, fdf *data)
{
	if (key == 0)
		data->rot_y += 0.05;
	else if (key == 2)
		data->rot_y -= 0.05;
	else if (key == 13)
		data->rot_x += 0.05;
	else if (key == 1)
		data->rot_x -= 0.05;
	else if (key == 12)
		data->rot_z -= 0.05;
	else if (key == 14)
		data->rot_z += 0.05;
	else
		projection(key, data);
}

int	deal_key(int key, fdf *data)
{
	printf("%d\n", key);
	if (key > 68)
		shift_scale(key, data);
	if (key < 53)
		camera(key, data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}
