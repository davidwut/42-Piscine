/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:39:39 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 12:45:14 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

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

void	fill_vertical(int ***data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][COL_UP][i] == g_size)
			j = -1;
			while (++j < g_size)
				data[BOARD][j][i] = j + 1;
		if (data[INPUT][COL_UP][i] == 1)
			data[BOARD][0][i] = g_size;
	}
	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][COL_DOWN][i] == g_size)
			j = -1;
			while (++j < g_size)
				data[BOARD][g_size - 1 - j][i] = j + 1;
		if (data[INPUT][COL_DOWN][i] == 1)
			data[BOARD][g_size - 1][i] = g_size;
	}
}

void	fill_horizontal(int ***data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][ROW_LEFT][i] == g_size)
			j = -1;
			while (++j < g_size)
				data[BOARD][i][j] = j + 1;
		if (data[INPUT][ROW_LEFT][i] == 1)
			data[BOARD][i][0] = g_size;
	}
	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][ROW_RIGHT][i] == g_size)
			j = -1;
			while (++j < g_size)
				data[BOARD][i][g_size - 1 - j] = j + 1;
		if (data[INPUT][ROW_RIGHT][i] == 1)
			data[BOARD][i][g_size - 1] = g_size;
	}
}

void	solve_helper(int ***data, int x, int y, int val)
{

}

void	solve(int **input)
{
	int	***data;

	data = malloc(sizeof(*data) * 3);
	data[INPUT] = input;
	data[BOARD] = init_board(data);
	fill_vertical(data);
	fill_horizontal(data);
	solve_helper(data, 0, 0, 1);
}
