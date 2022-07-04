/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:32:36 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 10:55:50 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	c;

	c = -1;
	while (str[++c])
		;
	return (c);
}

int	ft_atoi(char *str)
{
	long long	total;
	int			i;

	total = 0;
	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (total);
}

int	file_size(char *filename)
{
	int		size;
	int		total_size;
	char	buf[_BUF];
	int		fd;

	fd = open(filename, O_RDONLY);
	total_size = 0;
	size = read(fd, buf, _BUF);
	while (size != 0)
	{
		total_size += size;
		size = read(fd, buf, _BUF);
	}
	close(fd);
	return (total_size);
}
