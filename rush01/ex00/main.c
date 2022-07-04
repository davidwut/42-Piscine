/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:28:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 17:51:42 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

void	ft_putstr(char *str);
int		**parse(int argc, char **argv);
void	solve(int **input);

int	main(int argc, char **argv)
{
	int	**input;

	g_done = 0;
	input = parse(argc, argv);
	if (input != 0)
		solve(input);
	if (!g_done)
		ft_putstr("Error\n");
	return (0);
}
