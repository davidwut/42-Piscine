/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:14:18 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 15:57:17 by dwuthric         ###   ########.fr       */
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

void	print_formatted(char buf[16], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		special_print(buf[i]);
		if (i != size - 1)
			ft_putchar_fd(' ', 1);
	}
	while (i++ < 16)
		ft_putstr_fd("    ", 1);
	ft_putchar_fd('\n', 1);
}

void	copy(char to[16], char from[16])
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (from)
			to[i] = from[i];
		else
			to[i] = 0;
	}
}

int		ft_strcmp(char a[16], char b[16])
{
	while (*a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	print_line(int offset, char buf[16], int size, char last[16])
{
	if (ft_strcmp(buf, last) != 0)
	{
		print_offset(itoh(offset));
		ft_putstr_fd(" ", 1);
		print_formatted(buf, size);
	}
	else
	{
		ft_putstr_fd("*\n", 1);
	}
}

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
