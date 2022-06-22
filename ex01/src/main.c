/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:28:33 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 12:51:41 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		display_stdin(argv[0]);
	else
	{
		i = 0;
		while (++i < argc)
			if (display_file(argv[i]) == 0)
				print_err(argv[0], argv[i]);
	}
	return (0);
}
