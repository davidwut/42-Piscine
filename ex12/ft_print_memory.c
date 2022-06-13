/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:06:29 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 14:52:28 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		write(1, &c, 1);
}

void	print_addr(unsigned long long addr)
{
	char	*base;
	char	result[16];
	int		i;

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
		ft_putchar(result[i++], 1);
}

void	print_mem(unsigned char *addr, unsigned int size, char *base)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ', 1);
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
		i++;
	}
}

void	print_data(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if ((' ' <= addr[i] && addr[i] <= '~'))
			ft_putchar(addr[i], 1);
		else
			ft_putchar('.', 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	sz;
	unsigned char	*c;

	i = 0;
	c = addr;
	while (i * 16 < size)
	{
		if (size - i * 16 < 16)
			sz = size - i * 16;
		else
			sz = 16;
		print_addr((unsigned long long)c);
		ft_putchar(':', 1);
		print_mem(c, sz, "0123456789abcdef");
		ft_putchar(' ', 1);
		print_data(c, sz);
		ft_putchar('\n', 1);
		c += 16;
		i++;
	}
	return (addr);
}
