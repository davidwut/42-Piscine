/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:26:25 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 16:26:30 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	sigfig;

	sigfig = 1000000000;
	if (!nb)
	{
		putchar('0');
	}
	else
	{
		if (nb < 0)
		{
			putchar('-');
			nb *= -1;
		}
		while (sigfig > nb)
		{
			sigfig /= 10;
		}
		while (sigfig)
		{
			putchar(((nb / sigfig) % 10) + '0');
			sigfig /= 10;
		}
	}
}

#ifdef og

int	main(void)
{
	ft_putnbr(-2147483647);
	return (0);
}

#endif
