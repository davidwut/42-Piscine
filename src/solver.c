/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:55:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 13:27:34 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_map(int ***m, t_grid_info *info, int (*co)[2], int max)
{
	int	i;
	int	j;

	if (handle_edge_case(*m, info, &((*co)[0]), &((*co)[1])))
		return ;
	i = 0;
	while (++i < info->row_amount)
	{
		j = 0;
		while (++j < info->row_size)
		{
			if ((*m)[i][j] != 0)
			{
				(*m)[i][j] = min(*m, i, j) + 1;
				if (max < (*m)[i][j])
				{
					max = (*m)[i][j];
					(*co)[0] = i;
					(*co)[1] = j;
				}
			}
		}
	}
}

int	fill_edges(int ***m, t_grid_info *info, int (*co)[2])
{
	int	i;
	int	max;

	max = -1;
	i = -1;
	while (++i < info->row_size && max == -1)
	{
		if ((*m)[0][i] != 0)
		{
			(*co)[0] = 0;
			(*co)[1] = i;
			max = 1;
		}
	}
	i = -1;
	while (++i < info->row_amount && max == -1)
	{
		if ((*m)[i][0] != 0)
		{
			(*co)[0] = i;
			(*co)[1] = 0;
			max = 1;
		}
	}
	return (max);
}

void	fill_square(int ***map, int start_i, int start_j)
{
	int	**m;
	int	i;
	int	j;
	int	len;

	if (start_i == -1 || start_j == -1)
		return ;
	m = *map;
	i = -1;
	len = m[start_i][start_j];
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			m[start_i - i][start_j - j] = -1;
	}
}

void	solve(char *input)
{
	t_grid_info	*grid_info;
	int			**map;
	int			biggest_coords[2];
	int			max;

	grid_info = get_grid_info(input);
	if (!grid_info)
		return ;
	map = get_int_grid(input, grid_info);
	if (!map)
	{
		if (grid_info)
			free(grid_info);
		return ;
	}
	biggest_coords[0] = -1;
	biggest_coords[1] = -1;
	max = fill_edges(&map, grid_info, &biggest_coords);
	fill_map(&map, grid_info, &biggest_coords, max);
	fill_square(&map, biggest_coords[0], biggest_coords[1]);
	print_final_grid(map, grid_info);
	superfree(&map, &grid_info);
}
