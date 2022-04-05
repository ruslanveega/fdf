/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:31:03 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/24 19:12:08 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	int				dif;
	unsigned char	*ad1;
	unsigned char	*ad2;

	ad1 = (unsigned char *)s1;
	ad2 = (unsigned char *)s2;
	i = 1;
	if (n == 0)
		return (0);
	while (*ad1 != '\0' && *ad2 != '\0' && i != n)
	{
		if (*ad1 != *ad2)
			return (*ad1 - *ad2);
		ad1++;
		ad2++;
		i++;
	}
	dif = *ad1 - *ad2;
	return (dif);
}
