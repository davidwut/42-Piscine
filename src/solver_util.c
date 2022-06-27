/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:57:43 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 13:42:44 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	min(int a, int b, int c)
{
	int	temp;

	temp = a;
	if (temp > b)
		temp = b;
	if (temp > c)
		temp = c;
	return (temp);
}

int	handle_edge_case(int ***map, t_grid_info *info, int *k, int *l)
{
	if (info->row_amount == 1 && info->row_size == 1)
	{
		*k = 0;
		*l = 0;
	}
}