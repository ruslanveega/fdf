/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 01:56:50 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/22 01:56:55 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	float		x0;
	float		x1;
	float		y1;
	float		y0;
	int			scale;
	int			color;
	int			shift_y;
	int			shift_x;
	int			shift_z;
	double		alpha;
	double		rot_y;
	double		rot_z;
	double		rot_x;

	void		*mlx_ptr;
	void		*win_ptr;
}	t_fdf;

void	error(char *str);
int		main(int argc, char **argv);
void	free_char(char	**str);
void	read_map(char *map, t_fdf *data);
void	fill_data(t_fdf *data, int fd);
int		get_widht(char *map);
int		get_hight(char *map);
void	check_map_name(char *map);
int		check_elem(char *num);
void	check_widht(t_fdf *data, int fd);
void	free_fdf(t_fdf *data);
void	brosenham(t_fdf *data);
void	draw_map(t_fdf *data);
void	rotate_y(t_fdf *data, int **z0, int **z1);
void	rotate_x(t_fdf *data, int **z0, int **z1);
void	rotate_z(t_fdf *data);
void	data_prepare(int *z1, int *z0, t_fdf *data);
void	color(int z0, int z1, t_fdf *data);
int		deal_key(int key, t_fdf *data);
#endif
