/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:07:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 13:12:50 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char ** argv)
{
	char	*input;

	if (argc == 1)
		input = rd_stdin();
	else
		input = rd_file(argv[1]);
	if (input && check(input))
	{
		print_grid_from_str(input);
		ft_putstr("---------\n");
		print_int_grid_from_str(input);
		//solve(input);
	}
	else
		ft_putstr("map error\n");
	return (0);
}
