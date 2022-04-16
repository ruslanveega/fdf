/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:36:52 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/16 01:31:38 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, fdf *data)
{
	printf("%d\n", key);
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
	if (key == 13)
		data->alpha += 0.1;
	if (key == 1)
		data->alpha -= 0.1;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}


int	main(int argc, char **argv)
{
	fdf	*data;

	if (argc < 2)
		error("not enough args");
	data = malloc(sizeof(fdf));
	if (!data)
		error("allocaotion error");
	check_map_name(argv[1]);
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->scale = 30;
	data->shift_x = 70;
	data->shift_y = 0;
	data->alpha = 1;
	data->shift_z = 1;
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free_fdf(data);
	free(data);
	return (0);
}
