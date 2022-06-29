/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:14:18 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 19:25:58 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	print_offset(char *offset)
{
	int	i;

	i = -1;
	while (++i < 7 - ft_strlen(offset))
		ft_putchar_fd('0', 1);
	i = -1;
	while (++i < ft_strlen(offset))
		ft_putchar_fd(offset[i], 1);
}

void	special_print(char c)
{
	if (c == '\t')
		ft_putstr_fd(" \\t", 1);
	else if (c == '\n')
		ft_putstr_fd(" \\n", 1);
	else
		ft_putchar_non_printable(c);
}

void	print_formatted(char *buf)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		special_print(buf[i]);
		if (i != 16 - 1)
			ft_putchar_fd(' ', 1);
	}
	while (i++ < 16)
		ft_putstr_fd("    ", 1);
	ft_putchar_fd('\n', 1);
}

int		ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (i < 16 && a[i] == b[i - 16])
		i++;
	return (a[i] - b[i - 16]);
}

void	print_line(int offset, char *buf, int *repeat)
{
	if (*repeat)
	{
		ft_putstr_fd("*\n", 1);
	}
	else
	{
		print_offset(itoh(offset));
		ft_putstr_fd(" ", 1);
		print_formatted(buf + offset);
		*repeat = 0;
	}
	*repeat = ft_strcmp(buf + offset, buf + offset - 16) == 0;
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

void	hxd(char *filepath)
{
	int		file;
	int		size;
	int		offset;
	char	*buf;
	int		repeat;

	size = get_file_size(filepath);
	buf = malloc(size);
	file = open(filepath, O_RDONLY);
	read(file, buf, size);
	offset = 0;
	repeat = 0;
	while (offset < size)
	{
		print_line(offset, buf, &repeat);
		offset += 16;
	}
	print_offset(itoh(offset - 7));
	ft_putchar_fd('\n', 1);
	close(file);
}

/*
void	hxd(char *filepath)
{
	int		fd;
	int		offset;
	int		size;
	char	buf[16];
	char	last[16];

	fd = open(filepath, O_RDONLY);
	offset = 0;
	size = read(fd, buf, 16);
	copy(last, 0);
	while (size > 0)
	{
		print_line(offset, buf, size, last);
		copy(last, buf);
		offset += size;
		size = read(fd, buf, 16);
	}
	print_offset(itoh(offset));
	ft_putchar_fd('\n', 1);
	close(fd);
}
*/