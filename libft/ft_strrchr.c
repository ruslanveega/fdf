/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:28:37 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/23 01:36:13 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (const char)n)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == (const char)n)
		return ((char *)&str[i]);
	return (NULL);
}
