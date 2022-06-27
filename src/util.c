/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:10:44 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/26 17:10:45 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	strl(char *str)
{
	int	i;

	i = 0;
	while (str[0])
	{
		str ++;
		i ++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (str[0] && str[0] >= '0' && str[0] <= '9')
	{
		res = res * 10 + str[0] - '0';
		str ++;
	}
	return (res);
}

/* Returns number of characters in an int */
int	int_char_size(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

int	get_file_size(char *filename)
{
	int		total_size;
	int		size;
	int		file;
	char	buf[_BUF];

	total_size = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	size = read(file, buf, _BUF);
	while (size != 0)
	{
		total_size += size;
		size = read(file, buf, _BUF);
	}
	close(file);
	return (total_size);
}

int	count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}