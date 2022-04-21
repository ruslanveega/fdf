/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:36:52 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/21 02:46:48 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map_name(char *map)
{
	char	**map_name;

	map_name = ft_split(map, '.');
	if (ft_strlen(map_name[1]) != 3)
		error("incorrect map format");
	if (ft_strncmp(map_name[1], "fdf", 3))
		error("incorrect map format");
	if (map_name[2])
		error("incorrect map format");
	free_char(map_name);
}

int	check_elem(char *num)
{
	int		i;
	int		number;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != 10)
			error("wrong element in map");
		i++;
	}
	number = ft_atoi(num);
	return (number);
}

void	check_widht(fdf *data, int fd)
{
	int		width;
	char	**line;
	char	*tmp;
	int		i;

	i = 0;
	while (i++ < data->height)
	{
		width = 0;
		tmp = get_next_line(fd);
		line = ft_split(tmp, ' ');
		while (line[width])
			width++;
		if (width != data->width)
			error("incorrect map format");
		free(tmp);
		free_char(line);
	}
}
