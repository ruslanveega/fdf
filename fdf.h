/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:37:10 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/16 01:14:56 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct fdf
{
	int	width;
	int	height;
	int	**z_matrix;
	int	scale;
	int	color;
	int	shift_y;
	int	shift_x;
	int	shift_z;
	double	alpha;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	error(char *str);
int		main(int argc, char **argv);
void	free_char(char	**str);
void	read_map(char *map, fdf *data);
void	fill_data(fdf *data, int fd);
int		get_widht(char *map);
int		get_hight(char *map);
void	check_map_name(char *map);
int		check_elem(char *num);
void	check_widht(fdf *data, int fd);
void	free_fdf(fdf *data);
void	brosenham(float x0, float y0, float x1, float y1, fdf *data);
void	draw_map(fdf *data);
#endif
