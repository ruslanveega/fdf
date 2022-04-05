/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:36:52 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/26 03:05:02 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_hight(char *map)
{
	int		hight;
	int		fd;
	char	*line;

	hight = 0;
	fd = open(map, O_RDONLY, 0);
	while ((line = get_next_line(fd)))
	{
		hight++;
		free(line);
	}
	return (hight);
	close(fd);
}

int	get_widht(char *map)
{
	int		widht;
	int		fd;
	char	*line;
	char	**arr;
	int		i;

	i = 0;
	widht = 0;
	fd = open(map, O_RDONLY, 0);
	line = get_next_line(fd);
	arr = ft_split(line, ' ');
	free(line);
	while (arr[i++])
		widht++;
	free_char(arr);
	close(fd);
	return (widht);
}

void	fill_data(fdf *data, int fd)
{
	char	*line;
	char	**nums;
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		line = get_next_line(fd);
		nums = ft_split(line, ' ');
		while (j < data->width)
		{
			data->z_matrix[i][j] = check_elem(nums[j]);
			j++;
		}
		free(line);
		free_char(nums);
		i++;
	}
}

void	read_map(char *map, fdf *data)
{
	int		fd;
	int		i;

	data->height = get_hight(map);
	data->width = get_widht(map);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	if (!data->z_matrix)
		error("allocaotion error");
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(map, O_RDONLY, 0);
	check_widht(data, fd);
	close(fd);
	fd = open(map, O_RDONLY, 0);
	fill_data(data, fd);
	data->z_matrix[i] = NULL;
	close(fd);
}
