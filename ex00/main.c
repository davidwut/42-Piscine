/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:33:03 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/11 11:34:32 by dwuthric         ###   ########.fr       */
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
	while (i < length - 2)
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
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	print_line_formatted(x, 'A', 'B', 'C');
	i = 0;
	while (i < y - 2)
	{
		print_line_formatted(x, 'B', ' ', 'B');
		i++;
	}
	if (y > 1)
		print_line_formatted(x, 'C', 'B', 'A');
}

int	main(void)
{
	rush(4, 4);
	return (1);
}
