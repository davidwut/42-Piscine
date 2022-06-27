/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:24:40 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 16:20:04 by dwuthric         ###   ########.fr       */
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
