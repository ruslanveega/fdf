/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:53:53 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/16 14:46:57 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (const char)n)
			return ((char *)str);
		str++;
	}
	if (*str == (const char)n)
		return ((char *)str);
	return (NULL);
}
