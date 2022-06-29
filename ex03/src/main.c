/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:58:04 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 14:36:29 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac <= 2)
		return (0);
	else
	{
		i = 1;
		while (++i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd >= 0)
			{
				close(fd);
				hxd(av[i]);
			}
			else
				print_err(av[0], av[i]);
		}
	}
	return (0);
}
