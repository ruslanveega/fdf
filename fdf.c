/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:36:52 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/22 02:11:50 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->scale = 30;
	data->shift_x = 250;
	data->shift_y = 250;
	data->shift_z = 1;
	data->rot_y = -0.5;
	data->rot_x = -0.5;
	data->rot_z = 0.5;
	data->x0 = 0;
	data->y0 = 0;
	data->x1 = 0;
	data->y1 = 0;
}

int	close_win(t_fdf *data)
{
	free(data);
	free_fdf(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc < 2)
		error("not enough args");
	data = malloc(sizeof(t_fdf));
	if (!data)
		error("allocaotion error");
	check_map_name(argv[1]);
	read_map(argv[1], data);
	init_data(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_win, data);
	mlx_loop(data->mlx_ptr);
	free_fdf(data);
	free(data);
	return (0);
}
