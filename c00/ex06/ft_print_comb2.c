/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:47:36 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/16 17:13:28 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int x)
{
	if (x < 10)
	{
		ft_putchar('0');
		ft_putchar(x + '0');
	}
	else
	{
		ft_putchar((x / 10) + '0');
		ft_putchar((x % 10) + '0');
	}
}

void	ft_putnums(int x, int y)
{
	ft_putint(x);
	ft_putchar(' ');
	ft_putint(y);
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
				ft_putnums(a, b);
				if (!(a == 98 && b == 99))
				{
					ft_putchar(',');
					ft_putchar(' ');
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