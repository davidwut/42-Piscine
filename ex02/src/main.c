/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:42:57 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 11:01:08 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	handle_args(int ac, char **av, int arg)
{
	int	i;
	int	file;

	i = 2;
	while (++i < ac)
	{
		file = open(av[i], O_RDONLY);
		if (file < 0)
		{
			print_err(av[0], av[i]);
			continue ;
		}
		else
		{
			if (ac > 4)
				display_header(av[i], i, ac);
			display_last_nb(arg, av[i]);
			close (file);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_atoi(argv[2]) == -1)
			print_illegaloffset(argv[0], argv[2]);
		else
			display_stdin(argv[0]);
	}
	else if (argc >= 4)
	{
		if (ft_atoi(argv[2]) == -1)
			print_illegaloffset(argv[0], argv[2]);
		else
			handle_args(argc, argv, ft_atoi(argv[2]));
	}
	return (0);
}
