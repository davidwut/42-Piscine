/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:24:40 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 18:04:52 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*append_str(char str[_BUF], int size, char *buf)
{
	char	*res;
	int		i;
	int		len;

	len = strl(buf);
	res = malloc(len + size + 1);
	if (!res)
	{
		free(buf);
		return (NULL);
	}
	i = -1;
	while (++i < len)
		res[i] = buf[i];
	i = -1;
	while (++i < size)
		res[len + i] = str[i];
	res[len + i + 1] = 0;
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
