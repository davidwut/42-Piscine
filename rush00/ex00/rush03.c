/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:33:09 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/12 11:25:59 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
		print_line_formatted(width, 'A', 'B', 'C');
}
