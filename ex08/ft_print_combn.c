/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:20:02 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 10:09:55 by dwuthric         ###   ########.fr       */
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
	int	is_last_num;

	is_last_num = 1;
	i = 0;
	while (i < n)
	{
		putchar(x[i] + '0');
		if (x[i] != 10 - n + i)
			is_last_num = 0;
		i++;
	}
	if (!is_last_num)
	{
		putchar(',');
		putchar(' ');
	}
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

	i = 0;
	while (++i <= n)
		x[i - 1] = i - 1;
	while (x[0] <= 10 - n && x[n - 1] <= 9)
	{
		match_and_print(x, n);
		x[n - 1]++;
		i = n - 1;
		while (i > 0)
		{
			if (x[i] >= 10 - n + i)
			{
				x[i - 1]++;
				x[i] = x[i - 1] + 1;
			}
			i--;
		}
	}
}

#ifdef og

int	main(void)
{
	ft_print_combn(5);
	return (0);
}

#endif