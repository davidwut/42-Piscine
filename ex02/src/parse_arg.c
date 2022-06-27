/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:25:55 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 12:19:07 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
	-1 = illegal offset
	-2 = print help

*/

int	parse_arg(int ac, char **av, int *start)
{
	int	bcount;

	if (ac > 1 && av[1][0] == '-')
	{
		if (av[1][1] == 'c')
		{
			if (av[1][2] && '0' <= av[1][2] && av[1][2] <= '9')
			{
				bcount = ft_atoi(av[1] + 2);
				*start = 1;
			}
			else if (ac > 3 && '0' <= av[2][0] && av[2][0] <= '9')
			{
				bcount = ft_atoi(av[2]);
				*start = 2;
			}
		}
		else
			return (-2);
	}
	return (-1);
}
