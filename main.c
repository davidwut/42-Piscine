/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:28:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 12:47:15 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

void	ft_putstr(char *str);
int	**parse(int argc, char **argv);
void	solve(int **input);

int	main(int argc, char **argv)
{
	int	**input;

	input = parse(argc, argv);
	if (input == 0)
		ft_putstr("Error\n");
	else
		solve(input);
	return (0);
}


/*
"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
*/