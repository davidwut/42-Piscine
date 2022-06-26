/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:25:55 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/26 14:50:44 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	parse_arg(int ac, char **av, int *start)
{
	int	bcount;

	bcount = -1;
	if (ac > 1 && av[1][0] == '-')
	{
		if (av[1][1] == 'c')
		{
			if (av[1][2] && INRANGE(av[1][2], '0', '9'))
			{
				bcount = ft_atoi(av[1] + 2);
				*start = 1;
			}
			else if (ac > 3 && INRANGE(av[2][0], '0', '9'))
			{
				bcount = ft_atoi(av[2]);
				*start = 2;
			}
		}
		else
			print_help(av);
		if (bcount == -1)
			print_illegaloffset(av, *start);
	}
	return (bcount);
}
