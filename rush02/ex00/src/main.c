/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:25:19 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 11:25:43 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
		convert(av[1]);
	else if (ac == 3)
		//av[1] est le nouveau  dico
		//av[2] esst notre nombre a convertir
		convert(av[2]);
}