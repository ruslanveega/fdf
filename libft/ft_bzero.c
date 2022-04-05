/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:34:24 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/23 02:40:42 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t n)
{
	unsigned char	*ad;

	ad = (unsigned char *)dest;
	while (n > 0)
	{
		*ad = '\0';
		ad++;
		n--;
	}
	return (dest);
}
