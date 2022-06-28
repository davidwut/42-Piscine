/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:07:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 18:38:37 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
#include "check.c"
#include "parse.c"
#include "parse2.c"
#include "print_util.c"
#include "print_util2.c"
#include "rd_file.c"
#include "solver_util.c"
#include "solver.c"
#include "util.c"
#include "util2.c"
*/

#include <stdio.h>

void	do_the_thing(char *input)
{
	printf("---------\n");
	print_grid_info(get_grid_info(input));
	check()
	if (input && check(input))
		solve(input);
	else
		ft_putstr("map error\n");
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		do_the_thing(rd_stdin());
	else
	{
		i = 0;
		while (++i < argc)
			do_the_thing(rd_file(argv[i]));
	}
	return (0);
}
