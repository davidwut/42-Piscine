/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:30:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/30 13:31:41 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *a, char *b, int size)
{
	int	i;

	i = 0;
	while (i < size && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

int	get_file_size(char *filepath)
{
	int		total_size;
	int		size;
	int		file;
	char	buf[1024];

	file = open(filepath, O_RDONLY);
	total_size = 0;
	size = read(file, buf, 1024);
	while (size)
	{
		total_size += size;
		size = read(file, buf, 1024);
	}
	return (total_size);
}

char	*itoh(int offset)
{
	int		temp;
	int		i;
	char	*res;
	char	*hex;

	hex = "0123456789abcdef";
	temp = offset;
	i = 0;
	while (temp)
	{
		i++;
		temp /= 16;
	}
	res = malloc(i + 1);
	res[i] = 0;
	while (offset)
	{
		res[i-- - 1] = hex[offset % 16];
		offset /= 16;
	}
	return (res);
}
