/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 03:03:32 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/22 01:55:06 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	free_char(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_fdf(t_fdf *data)
{
	int	i;
	int	**matrix;

	matrix = data->z_matrix;
	i = 0;
	while (i <= data->height)
	{
		free(matrix[i]);
		i++;
	}
	free(data->z_matrix);
}
