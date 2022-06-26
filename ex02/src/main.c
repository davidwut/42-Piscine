/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:42:57 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/26 14:49:31 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	bcount;

	start = -1;
	if (argc == 1)
		display_stdin(argv[0]);
	else
	{
		bcount = parse_arg(argc, argv, &start);
		if (bcount == -1)
		{
			if (argc < 4)
				display_stdin(argv[0]);
		}
		else
		{
			i = start;
			while (++i < argc)
			{
				if (display_last_nb(argv[i], bcount) == 0)
					print_err(argv[0], argv[i]);
			}
		}
	}
	return (0);
}
