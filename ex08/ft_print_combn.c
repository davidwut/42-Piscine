/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:20:02 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 17:20:04 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int *x, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		putchar(x[i] + '0');
		i++;
	}
	putchar(',');
	putchar(' ');
}

int	match(int *arr, int n)
{
	int	i;
	int	flags[10];

	i = 0;
	while (i < 10)
	{
		flags[i] = 0;
		i++;
	}
	i = 0;
	while (i < n)
	{
		flags[arr[i]]++;
		if (flags[arr[i]] > 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	x[10];
	int	ptr;
	int	i;

	ptr = 0;
	while (++ptr <= n)
		x[ptr - 1] = ptr - 1;
	ptr = n - 1;
	i = 0;
	while (ptr >= 0)
	{
		if (!ptr)
			x[ptr] = x[ptr - 1] + 1;
		while (x[ptr] < 9 - i)
		{
			if (match(x, n))
				ft_putnbr(x, n);
			x[ptr]++;
		}
		x[ptr] = 0;
		ptr--;
		i++;
	}
}

#ifdef og

int	main(void)
{
	ft_print_combn(2);
	return (0);
}

#endif