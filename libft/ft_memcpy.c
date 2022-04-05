/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:44:52 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/24 18:01:53 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ad_s;
	char	*ad_d;

	ad_s = (char *)src;
	ad_d = (char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*ad_d = *ad_s;
		n--;
		ad_d++;
		ad_s++;
	}
	return (dest);
}
