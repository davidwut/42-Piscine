/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:02:59 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 15:34:55 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	c;

	c = -1;
	while (str[++c])
		;
	return (c);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnstr(char *str, int n)
{
	write(1, str, n);
}

void	ft_puthex(int c, int pass)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 0)
		c += 256;
	if (!pass)
		ft_putchar_fd('\\', 1);
	if (c > 15)
		ft_puthex(c / 16, 1);
	ft_putchar_fd(hex[c % 16], 1);
}

void	ft_putchar_non_printable(char c)
{
	int	i;
	int	temp;

	if (c < 0)
		temp = c + 256;
	else
		temp = c;
	i = -1;
	while (++i < ((temp / 255) + 2) % 3)
		ft_putchar_fd(' ', 1);
	if (' ' <= c && c <= '~')
		ft_putchar_fd(c, 1);
	else
		ft_puthex(c, 0);
}
