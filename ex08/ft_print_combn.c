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
	while (i <= n)
	{
		putchar(x[i] + '0');
	}
}

int	match(int *arr, int n)
{
	int	i;
	int	flags[10];

	i = 0;
	while (i <= 10)
	{
		flags[i] = 0;
		i++;
	}
	i = 0;
	while (i <= n)
	{
		flags[arr[i]]++;
		if (flags[arr[i]] > 1)
		{
			return (0);
		}
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	x[10];
	int	tempn;
	int	i;

	tempn = 0;
	while (++tempn <= n)
	{
		x[tempn - 1] = tempn - 1;
	}
	tempn = n;
	i = 0;
	while (tempn)
	{
		while (x[tempn - 1] <= 9 - i)
		{
			x[tempn - 1]++;
			if (match(x, n))
			{
				ft_putnbr(x, n);
			}
		}
		tempn--;
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