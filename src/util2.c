/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:24:40 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/28 10:47:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*append_str(char str[_BUF], int size, char *buf, int buf_size)
{
	char	*res;
	int		i;

	res = malloc(buf_size + size + 1);
	if (!res)
	{
		free(buf);
		return (NULL);
	}
	i = -1;
	while (++i < buf_size)
		res[i] = buf[i];
	i = -1;
	while (++i < size)
		res[buf_size + i] = str[i];
	res[buf_size + i + 1] = 0;
	free(buf);
	return (res);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	destlen;

	destlen = 0;
	while (dest[destlen])
		destlen ++;
	i = 0;
	while (src[i] && i < nb)
	{
		dest[i + destlen] = src[i];
		i ++;
	}
	dest[destlen + i] = 0;
	return (dest);
}
