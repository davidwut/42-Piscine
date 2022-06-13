/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:06:29 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/12 12:00:53 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex12_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex_formatted(unsigned long hex, int size)
{
	char	*translation;
	char	result[16];
	int i;

	translation = "0123456789abcdef";
	i = 0;
	while (i < 16)
		result[i++] = '0';
	i = 0;
	while (hex)
	{
		result[15 - i] = translation[hex % 16];
		hex /= 16;
		i++;
	}
	i = 16 - size;
	while (i < 16)
		ex12_putchar(result[i++]);
}

void	read_hex_from_mem(void *addr, unsigned int size)
{
	int i;
	unsigned char byte;
	char *translation;

	translation = "0123456789abcdef";
	i = 0;
	while (i < 16 && i < size)
	{
		byte = *(((unsigned char *)addr) + i);
		ex12_putchar(translation[byte / 16]);
		ex12_putchar(translation[byte % 16]);
		if((i + 1) % 3)
			ex12_putchar(' ');
		i++;
		size -= 16;
	}
}

void	read_str_from_mem(void *addr, unsigned int size)
{
	int i;

	while (size)
	{
		i = 0;
		while (i < size % 16)
		{
			ex12_putchar(*(char *)(addr + i));
			i++;
		}
		size -= 16;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	int lines;

	i = 0;
	lines = 0;
	while (i < 16 && i < size)
	{
		print_hex_formatted((unsigned long) (addr + i + 16 * lines), 16);
		ex12_putchar(':');
		ex12_putchar(' ');
		read_hex_from_mem(addr + i + 16 * lines, 16);
		ex12_putchar(' ');
		i++;
		size -= 16;
		if (i == 16)
			lines++;
	}

	return addr;
}
