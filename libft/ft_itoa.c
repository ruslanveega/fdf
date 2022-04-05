/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:15:41 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/24 01:10:28 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*num_to_str(int n, int count, int sign)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (count + 1));
	if (!res)
		return (res);
	res[count] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--count] = (char)((n % 10) * sign) + '0';
		n = n / 10;
	}
	if (sign < 0)
		res[--count] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	int		num;
	int		count;
	char	*res;
	int		sign;

	num = n;
	count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	sign = 1;
	if (n < 0)
		sign = -1;
	count += (n <= 0);
	res = num_to_str(n, count, sign);
	return (res);
}
