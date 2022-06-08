/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:34:56 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 13:35:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int x)
{
	x += '0';
	write(1, &x, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 2;
	while (++a <= 7)
	{
		while (++b <= 8)
		{
			while (++c <= 9)
			{
				if (a != b && a != c && b != c)
				{
					ft_putint(a);
					ft_putint(b);
					ft_putint(c);
					ft_putchar(',');
				}
			}
			c = 2;
		}
		b = 1;
	}
}

#ifdef og

int	main(void)
{
	ft_print_comb();
	return (0);
}

#endif
