/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:42:05 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/12 17:33:03 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex04_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int n, char *base)
{
	int	baselen;
	int	i;

	while (base[i] != '\0')
		i++;
	baselen = 1;
	i = 0;
	if (n < 0)
	{
		ex04_putchar('-');
		n *= -1;
	}
	if (n > baselen - 1)
		ft_putnbr_base(n / baselen, base);
	ex04_putchar(base[(n % baselen)]);
}
