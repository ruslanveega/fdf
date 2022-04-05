/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:13:56 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/23 02:46:19 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ret;

	ret = malloc(number * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, number * size);
	return (ret);
}
