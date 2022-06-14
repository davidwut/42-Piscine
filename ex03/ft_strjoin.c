/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:15:48 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/14 15:40:56 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dst, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	dst_size;

	dst_size = 0;
	i = 0;
	while (dst[i] != '\0')
	{
		dst_size++;
		i++;
	}
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		total_size;

	if (size <= 0)
		return ((char *)malloc(0));
	i = 0;
	total_size = ft_strlen(sep) * size - 1;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		i++;
	}
	res = (char *)malloc(sizeof(char) * total_size + 1);
	i = 0;
	while (i < size)
	{
		ft_strncat(res, strs[i], ft_strlen(strs[i]));
		if (i != size - 1)
			ft_strncat(res, sep, ft_strlen(sep));
		i++;
	}
	return (res);
}
