/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:07:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 17:44:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_the_thing(char *input, int linebreak)
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
	if (linebreak)
		ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		do_the_thing(rd_stdin(), 0);
	else
	{
		i = 0;
		while (++i < argc)
			do_the_thing(rd_file(argv[i]), i < argc - 1);
	}
	return (0);
}
