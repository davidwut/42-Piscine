/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:47:36 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 14:47:38 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putint(int x)
{
	if (x < 10)
	{
		putchar('0');
		putchar(x + '0');
	}
	else
	{
		putchar((x / 10) + '0');
		putchar((x % 10) + '0');
	}
}

void	putnums(int x, int y)
{
	putint(x);
	putchar(' ');
	putint(y);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a != b)
			{
				putnums(a, b);
				if (!(a == 98 && b == 99))
				{
					putchar(',');
					putchar(' ');
				}
			}
			b++;
		}
		a++;
	}
}

#ifdef og

int	main(void)
{
	ft_print_comb2();
	return (0);
}

#endif