/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:33:09 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/11 11:07:16 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_line_formatted(int length, char a, char b, char c)
{
	int	i;

	ft_putchar(a);
	i = 0;
	while (i < length - 1)
	{
		ft_putchar(b);
		i++;
	}
	if (length > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (!x || !y)
		return ;
	print_line_formatted(x, 'A', 'B', 'C');
	while (y > 1)
	{
		print_line_formatted(x, 'B', ' ', 'B');
		y--;
	}
	print_line_formatted(x, 'C', 'B', 'A');
}
