/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:07:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 13:02:12 by dwuthric         ###   ########.fr       */
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

void	do_the_thing(char *input)
{
	if (input && check(input))
		solve(input);
	else
		ft_putstr_fd("map error\n", STDERR_FILENO);
	if (input)
	{
		free(input);
		input = NULL;
	}
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
