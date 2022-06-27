/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:07:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 14:00:54 by dwuthric         ###   ########.fr       */
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
	ft_putstr("check: ");
	ft_putnbr(check(input));
	ft_putchar('\n');
	if (input && check(input))
	{
		solve(input);
	}
	else
		ft_putstr("map error\n");
	return (0);
}
