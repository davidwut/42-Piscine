/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:20:02 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/16 17:41:47 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	print_num(int *num, int n)
{
	int i;

	i = 0;
	while (i < n)
		ft_putchar(num[i++] + '0');
	if (!(num[0] == 10 - n && num[n - 1] == 9))
			ft_putstr(", ");
}

void	adjust_num(int *num, int n)
{
	int	i;
	int	carry;


	i = 0;
	carry = 0;
	while (num[n - 1 - i] > 9 - i)
	{
		num[n - 2 - i]++;
		i++;
	}
	i = 1;
	while (i < n)
	{
		if (num[i] > 10 - n + i)
			num[i] = num[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int num[10];
	int i;

	i = -1;
	while (++i < n)
		num[i] = i;
	while (num[0] <= 10 - n && num[n - 1] <= 9)
	{
		print_num(num, n);
		num[n - 1]++;
		if (n > 1)
			adjust_num(num, n);
	}
}
