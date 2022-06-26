/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:17:53 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/26 13:42:54 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	total;
	int			neg;

	total = 0;
	neg = 1;
	i = 0;
	while(str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!(INRANGE(str[i], '0', '9')))
			return (-1);
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (total);
}
