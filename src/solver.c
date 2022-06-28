/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:55:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 18:10:58 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_map(int ***m, t_grid_info *info, int *k, int *l)
{
	int	i;
	int	j;
	int	max;

	if (handle_edge_case(*m, info, k, l))
		return ;
	i = 0;
	max = -1;
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
					*k = i;
					*l = j;
				}
			}
		}
	}
}

void	fill_square(int ***map, int start_i, int start_j)
{
	int	**m;
	int	i;
	int	j;
	int	len;

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

void	print_final_char(int x, t_grid_info *info)
{
	if (x == -1)
		ft_putchar(info->full_char);
	else if (x == 0)
		ft_putchar(info->wall_char);
	else
		ft_putchar(info->empty_char);
}

void	print_final_grid(int **map, t_grid_info *info)
{
	int	i;
	int	j;
	int	row;
	int	col;
	int	use_color;

	use_color = 0;
	row = info->row_amount;
	col = info->row_size;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (use_color)
				print_final_char_color(map[i][j], info);
			else
				print_final_char(map[i][j], info);	
		}
		ft_putchar('\n');
	}
}

void	solve(char *input)
{
	t_grid_info	*grid_info;
	int			**map;
	int			biggest_col;
	int			biggest_row;

	grid_info = get_grid_info(input);
	map = get_int_grid(input, grid_info);
	fill_map(&map, grid_info, &biggest_col, &biggest_row);
	fill_square(&map, biggest_col, biggest_row);
	print_final_grid(map, grid_info);
	superfree(&map, &grid_info);
}
