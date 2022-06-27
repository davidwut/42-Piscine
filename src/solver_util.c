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

#include <stdio.h>

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

void	handle_horizontal(int **map, t_grid_info *info, int *k, int *l)
{
	printf("horizontal\n");
	int	i;

	i = 0;
	*k = 0;
	*l = -1;
	while ((i < info->row_size) && (*l == -1))
	{
		printf("map[0][i]: %d\n", map[0][i]);
		if (map[0][i])
			*l = i;
		i ++;
	}
}

void	handle_vertical(int **map, t_grid_info *info, int *k, int *l)
{
	printf("vertical\n");
	int	i;

	i = 0;
	*k = -1;
	*l = 0;
	while (i < info->row_amount && *k == -1)
	{
		if (map[i][0])
			*k = i;
		i ++;
	}
}

int	handle_edge_case(int **map, t_grid_info *info, int *k, int *l)
{	
	if (!(info->row_amount == 1 || info->row_size == 1))
		return (0);
	if (info->row_amount == 1)
		handle_horizontal(map, info, k, l);
	else
		handle_vertical(map, info, k, l);
	printf("k: %d, l: %d\n", *k, *l);
	return (1);
}