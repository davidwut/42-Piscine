/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bheight: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:33:03 bheight dwuthric          #+#    #+#             */
/*   Updated: 2022/06/11 11:39:57 bheight dwuthric         ###   ########.fr       */
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

void	rush(int width, int height)
{
	int	i;

	if (width <= 0 || height <= 0)
		return ;
	print_line_formatted(width, 'A', 'B', 'C');
	i = 0;
	while (i < height - 2)
	{
		print_line_formatted(width, 'B', ' ', 'B');
		i++;
	}
	if (height > 1)
		print_line_formatted(width, 'C', 'B', 'A');
}

int	main(void)
{
	rush(4, 4);
	return (1);
}
