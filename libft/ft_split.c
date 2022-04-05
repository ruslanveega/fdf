/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:21:31 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/24 01:11:24 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char const *s, char c)
{
	unsigned int	num;
	unsigned int	i;

	num = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
			i = 0;
		if (i == 0)
		{
			if (*s != c)
			{
				i = 1;
				num++;
			}
		}
		s++;
	}
	return (num);
}

static void	free_mem(char **arr, int el)
{
	while (--el >= 0)
	{
		free(arr[el]);
	}
	free(arr);
}

char	**make_arr(char const *s, char c, char **ret, int len)
{
	int		i;
	int		k;
	int		n_elem;

	i = 0;
	n_elem = 0;
	while (n_elem < len)
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i + k] != c && s[i + k] != '\0')
			k++;
		ret[n_elem] = ft_substr(s, (unsigned int)i, (size_t)k);
		if (ret[n_elem] == NULL)
		{
			free_mem(ret, n_elem);
			return (NULL);
		}
		i += k;
		n_elem++;
	}
	ret[n_elem] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		len;

	if (!s)
		return (NULL);
	len = num_words(s, c);
	ret = (char **)ft_calloc((len + 1), sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret = make_arr(s, c, ret, len);
	return (ret);
}
