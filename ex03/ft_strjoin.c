/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:15:48 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/21 18:09:52 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strncat(char *dst, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	dst_size;

	dst_size = 0;
	i = -1;
	while (dst[++i] != '\0')
		dst_size++;
	i = -1;
	while (src[++i] != '\0' && i < n)
		dst[dst_size + i] = src[i];
	dst[dst_size + i] = '\0';
	return (dst);
}

char	*init_str(int size)
{
	char	*res;
	int		i;

	res = malloc(sizeof(*res) * size);
	i = -1;
	while (++i < size)
		res[i] = 0;
	return (res);
}

char	*ft_strjoin(int size, char **list, char *sep)
{
	int		i;
	int		total_size;
	char	*res;

	if (size <= 0)
		return (init_str(1));
	total_size = ft_strlen(sep) * (size - 1);
	i = -1;
	while (++i)
		total_size += ft_strlen(list[i]);
	res = init_str(total_size + 1);
	i = -1;
	while (++i < size)
	{
		res = ft_strncat(res, list[i], ft_strlen(list[i]));
		if (i != size - 1)
			res = ft_strncat(res, sep, ft_strlen(sep));
	}
	return (res);
}
