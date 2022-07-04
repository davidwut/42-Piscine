/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:20:50 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/21 10:17:47 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(int c, int pass)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 0)
		c += 256;
	if (!pass)
		ft_putchar('\\');
	if (c > 15)
		ft_puthex(c / 16, 1);
	if (!pass && c < 16)
		ft_putchar('0');
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (' ' <= str[i] && str[i] <= '~')
			ft_putchar(str[i]);
		else
			ft_puthex(str[i], 0);
		i++;
	}
}
