/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:17:53 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 12:11:46 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	long long	total;
	int			i;
	int			neg;

	total = 0;
	neg = 1;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (total);
}
