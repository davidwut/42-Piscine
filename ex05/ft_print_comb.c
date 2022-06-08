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

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putnum(int x, int y, int z)
{
	putchar(x + '0');
	putchar(y + '0');
	putchar(z + '0');
}

void	putformat(int x, int y, int z)
{
	putnum(x, y, z);
	if (!(x == 7 && y == 8 && z == 9))
	{
		putchar(',');
		putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				if (a != b && a != c && b != c)
				{
					putformat(a, b, c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

#ifdef og

int	main(void)
{
	ft_print_comb();
	return (0);
}

#endif
