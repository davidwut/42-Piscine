/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:06:29 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 14:33:24 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_addr(unsigned long long addr)
{
	char	*base;
	char	result[16];
	int i;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
		result[i++] = '0';
	i = 0;
	while (addr)
	{
		result[15 - i] = base[addr % 16];
		addr /= 16;
		i++;
	}
	i = 0;
	while (i < 16)
		ft_putchar(result[i++]);
}

void	print_mem(unsigned char *addr, unsigned int size)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	while (i < size)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		if (addr[i] < 16)
		{
			ft_putchar('0');
			ft_putchar(base[addr[i] % 16]);
		}
		else
		{
			ft_putchar(base[addr[i] / 16]);
			ft_putchar(base[addr[i] % 16]);
		}
		i++;
	}
}

void	print_data(unsigned char *addr, unsigned int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if ((' ' <= addr[i] && addr[i] <= '~'))
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	int sz;
	unsigned char *c;

	i = 0;
	c = (unsigned char*) addr;
	while (i * 16 < size)
	{
		if (size - i * 16 < 16)
			sz = size - i * 16;
		else
			sz = 16;
		print_addr((unsigned long long)c);
		ft_putchar(':');
		print_mem(c, sz);
		ft_putchar(' ');
		print_data(c, sz);
		ft_putchar('\n');
		c += 16;
		i++;
	}
	return addr;
}
