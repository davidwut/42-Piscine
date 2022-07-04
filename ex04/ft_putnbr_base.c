/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:42:05 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/16 11:07:39 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef long long	t_ll;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base_incorrect(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base_helper(t_ll n, char *base)
{
	int	baselen;

	if (is_base_incorrect(base))
		return ;
	baselen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > baselen - 1)
		ft_putnbr_base_helper(n / baselen, base);
	ft_putchar(base[(n % baselen)]);
}

void	ft_putnbr_base(int n, char *base)
{
	ft_putnbr_base_helper((t_ll)n, base);
}
