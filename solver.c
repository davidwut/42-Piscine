/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:39:39 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 14:03:34 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
void	print_board(int **board);
void	fill_vertical(int ***data);
void	fill_horizontal(int ***data);
int	valid_solution(int ***data);

int	**init_board(int ***data)
{
	int **board;
	int	i;
	int	j;

	board = malloc(sizeof(*board) * g_size);
	i = 0;
	while (i < g_size)
	{
		board[i] = malloc(sizeof(*board[i]) * g_size);
		j = 0;
		while (j < g_size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

int	valid_placement(int ***data, int x, int y, int val)
{

}

void	solve_helper(int ***data, int x, int y)
{
	int	val;

	if (x == g_size && y == g_size && valid_solution(data))
		print_board(data[BOARD]);
	else if (y == g_size)
		solve_helper(data, x + 1, 0);
	else
	{
		val = 0;
		while (++val <= g_size)
		{
			if (valid_placement(data, x, y, val))
			{
				data[BOARD][x][y] = val;
				solve_helper(data, x, y + 1);
			}
		}
	}
}

void	solve(int **input)
{
	int	***data;

	data = malloc(sizeof(*data) * 3);
	data[INPUT] = input;
	data[BOARD] = init_board(data);
	fill_vertical(data);
	fill_horizontal(data);
	solve_helper(data, 0, 0);
}
