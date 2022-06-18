/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:32:56 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/18 17:15:08 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

typedef struct s_cell {
	int possible_values[SIZE];
} t_cell;

void	print_board(int board[SIZE][SIZE]);

void	solve(int board[SIZE][SIZE], int input[SIZE * 4], int pos)
{
	int	i;
	int	j;

	if (pos == SIZE * 4)
	{
		print_board(board);
	}
	else
	{
		i = 1;
		while (i <= 4)
		{
			j = 1;
			while (j <= 4)
			{
				if (is_valid_placement(board, input, i, j))
				{
					board
				}
			}
		}
	}
}

void	solve_wrapper(int input[16])
{
	int	board[4][4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
		j = -1;
		while (++j < 4)
			board[i][j] = -1;
	solve(board, input, 0);
}