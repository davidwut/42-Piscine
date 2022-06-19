/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:39:39 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 17:21:42 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "definitions.h"

void	ft_putstr(char *str);
void	print_board(int **board);
int		fill_colup(int ***data);
int		fill_coldown(int ***data);
int		fill_rowleft(int ***data);
int		fill_rowright(int ***data);
int		valid_solution(int ***data);

int	**init_board(void)
{
	int	**board;
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
	int	i;

	if (data[BOARD][x][y] == val)
		return (1);
	else if (data[BOARD][x][y] != 0)
		return (0);
	i = -1;
	while (++i < x)
		if (data[BOARD_CPY][i][y] == val)
			return (0);
	i = -1;
	while (++i < y)
		if (data[BOARD_CPY][x][i] == val)
			return (0);
	if (data[BOARD_CPY][x][y] != 0)
		return (0);
	return (1);
}

void	board_clear(int ***data, int x, int val)
{
	int	i;

	i = -1;
	while (++i < g_size)
		if (data[BOARD_CPY][x][i] == val)
			data[BOARD_CPY][x][i] = 0;
}

void	solve_helper(int ***data, int x, int y)
{
	int	val;

	if (x == g_size && valid_solution(data))
	{
		g_done = 1;
		print_board(data[BOARD_CPY]);
	}
	else if (y == g_size)
		solve_helper(data, x + 1, 0);
	else if (x == g_size)
		(void)x;
	else
	{
		val = 0;
		while (++val <= g_size)
		{
			if (valid_placement(data, x, y, val))
			{
				data[BOARD_CPY][x][y] = val;
				solve_helper(data, x, y + 1);
				data[BOARD_CPY][x][y] = 0;
			}
		}
	}
}

void	solve(int **input)
{
	int	***data;

	data = malloc(sizeof(*data) * 3);
	data[INPUT] = input;
	data[BOARD] = init_board();
	data[BOARD_CPY] = init_board();
	fill_colup(data);
	fill_coldown(data);
	fill_rowleft(data);
	fill_rowright(data);
	solve_helper(data, 0, 0);
}
