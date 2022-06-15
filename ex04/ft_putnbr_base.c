/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:42:05 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/15 14:16:28 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex04_putchar(char c)
{
	write(1, &c, 1);
}

int	ex04_ft_isspace(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = " \f\n\r\t\v";
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ex04_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ex04_is_base_incorrect(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int n, char *base)
{
	int	baselen;
	int	i;

	if (ex04_is_base_incorrect(base))
		return ;
	baselen = ex04_ft_strlen(base);
	i = 0;
	if (n == -2147483648)
	{
		ex04_putchar('-');
		ex04_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ex04_putchar('-');
		n *= -1;
	}
	if (n > baselen - 1)
		ft_putnbr_base(n / baselen, base);
	ex04_putchar(base[(n % baselen)]);
}
