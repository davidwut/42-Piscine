/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:05:03 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 16:07:32 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_valid(char *operator)
{
	char	*valid_symbols;
	int		i;

	valid_symbols = "+-/*%";
	if (operator[0] && operator[1])
		return (-1);
	i = -1;
	while (++i < 5)
		if (valid_symbols[i] == operator[0])
			return (i);
	return (-1);
}

void	init_list(void (*list[5])(int, int))
{
	list[0] = &addition;
	list[1] = &substraction;
	list[2] = &division;
	list[3] = &multiplication;
	list[4] = &modulo;
}

int	main(int argc, char **argv)
{
	void	(*operations[5])(int, int);
	int		op;

	init_list(operations);
	if (argc == 4)
	{
		op = is_valid(argv[2]);
		if (op == -1)
		{
			ft_putstr("0\n");
			return (0);
		}
		operations[op](ft_atoi(argv[1]), ft_atoi(argv[3]));
		ft_putstr("\n");
	}
	return (0);
}
