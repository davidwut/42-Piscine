/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:55:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 14:10:52 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pg(int **map, s_grid_info *grid_info);

void	fill_map(int ***map, s_grid_info *info)
{
	int	i;
	int	j;
	int	**m;

	m = *map;
	i = 1;
	while (i < info->row_amount)
	{
		j = 1;
		while (j < info->row_size)
		{
			if (m[i][j] != 0)
				m[i][j] = min(m[i - 1][j], m[i][j - 1], m[i - 1][j - 1]) + 1;
			j++;
		}
		i++;
	}
}

void	solve(char *input)
{
	s_grid_info	*grid_info;
	int		**map;

	grid_info = get_grid_info(input);
	map = get_int_grid(input);
	pg(map, grid_info);
	fill_map(&map, grid_info);
	ft_putstr("\n-----\n");
	pg(map, grid_info);
}


void	pg(int **map, s_grid_info *grid_info)
{
	for (int i = 0; i < grid_info->row_amount; i++)
	{
		for (int j = 0; j < grid_info->row_size; j++)
		{
			ft_putnbr(map[i][j]);
			ft_putstr(" ");
		}
		ft_putchar('\n');
	}
}
