/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:07:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 17:58:55 by dwuthric         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	*input;

	if (argc == 1)
		input = rd_stdin();
	else
		input = rd_file(argv[1]);
	if (input && check(input))
	{
		solve(input);
	}
	else
		ft_putstr("map error\n");
	return (0);
}
