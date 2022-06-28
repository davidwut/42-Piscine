/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:50 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 18:44:33 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	handle_args(int ac, char **av)
{
	if (ac == 1)
		display_stdin(av[0]);
	else if (ac == 2)
		two_args(av);
	else
		n_args(ac, av);
}

void	two_args(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'c')
	{
		if (ft_strlen(av[1]) == 2)
			print_help(av[0]);
		else if(ft_atoi(av[1] + 2) == -1)
			print_illegaloffset(av[0], av[1] + 2);
		else
			display_stdin(av[0]);
	}
}

void	n_args(int ac, char **av)
{
	if (ft_strlen(av[1]) > 2)
		together(ac, av);
	else
		apart(ac, av);
}

void	together(int ac, char **av)
{
	int	bcount;
	int	i;

	bcount = ft_atoi(av[1] + 2);
	if (bcount == -1)
		print_illegaloffset(av[0], av[1] + 2);
	else
	{
		i =
	}
}

void	apart(int ac, char **av)
{
	(void) ac;
	(void) av;
}
