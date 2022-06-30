/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:14:18 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/30 13:32:16 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_offset(char *offset)
{
	int	i;

	i = -1;
	while (++i < 8 - ft_strlen(offset))
		ft_putchar_fd('0', 1);
	i = -1;
	while (++i < ft_strlen(offset))
		ft_putchar_fd(offset[i], 1);
}

void	print_mem(char *addr, int size, char *base)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (i != 0)
			ft_putchar(' ', 1 + (i % 8 == 0));
		if (i < size)
		{
			if (addr[i] < 16)
			{
				ft_putchar('0', 1);
				ft_putchar(base[addr[i] % 16], 1);
			}
			else
			{
				ft_putchar(base[addr[i] / 16], 1);
				ft_putchar(base[addr[i] % 16], 1);
			}
		}
		else
			ft_putchar(' ', 2);
	}
}

void	print_data(char *addr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if ((' ' <= addr[i] && addr[i] <= '~'))
			ft_putchar(addr[i], 1);
		else
			ft_putchar('.', 1);
	}
}

void	print_line(int offset, char *buf, int size)
{
	if (offset < 16 || (offset >= 16
			&& ft_strcmp(buf + offset, buf + offset - 16, size) != 0))
	{
		print_offset(itoh(offset));
		ft_putchar(' ', 2);
		print_mem(buf + offset, size, "0123456789abcdef");
		ft_putstr_fd("  |", 1);
		print_data(buf + offset, size);
		ft_putstr_fd("|\n", 1);
	}
	else if ((offset <= 16
			&& ft_strcmp(buf + offset, buf + offset - 16, size) == 0)
		|| (ft_strcmp(buf + offset, buf + offset - 16, size) == 0
			&& ft_strcmp(buf + offset, buf + offset - 32, 16) != 0))
		ft_putstr_fd("*\n", 1);
}

void	hxd(char *filepath)
{
	int		file;
	int		size;
	int		offset;
	int		temp;
	char	*buf;

	size = get_file_size(filepath);
	buf = malloc(size);
	file = open(filepath, O_RDONLY);
	read(file, buf, size);
	offset = 0;
	while (offset < size)
	{
		temp = 16;
		if (size - offset < 16)
			temp = size - offset;
		print_line(offset, buf, temp);
		offset += temp;
	}
	print_offset(itoh(offset));
	ft_putchar_fd('\n', 1);
	close(file);
}
