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

void	putformat(int *x, int n)
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

void	match_and_print(int *arr, int n)
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
			return ;
		i++;
	}
	putformat(arr, n);
}

void	ft_print_combn(int n)
{
	int	x[10];
	int	i;

	x[0] = 0;
	i = 0;
	while (x[0] <= 10 - n)
	{
		while (i < n)
		{
			if (i)
				x[i] = x[i - 1] + 1;
			i++;
		}
		i--;
		while (x[i] <= 10 - n + i)
		{
			match_and_print(x, n);
			x[i]++;
		}
		if (i)
			x[i - 1]++;
			i--;
	}
}

#ifdef og

int	main(void)
{
	ft_print_combn(3);
	return (0);
}

#endif