/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:24:40 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/28 13:21:15 by dwuthric         ###   ########.fr       */
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
		if (buf)
			free(buf);
		return (NULL);
	}
	i = -1;
	while (++i < buf_size)
		res[i] = buf[i];
	i = -1;
	while (++i < size)
		res[buf_size + i] = str[i];
	res[buf_size + i] = 0;
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

int	ft_atoi_n(char *str, int n)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[0] && str[0] >= '0' && str[0] <= '9' && i < n)
	{
		res = res * 10 + str[0] - '0';
		str ++;
		i ++;
	}
	return (res);
}

/* Basically counts until a newline is reached */
int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[0] && str[0] != '\n')
	{
		i ++;
		str ++;
	}
	return (i);
}
