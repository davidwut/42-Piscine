/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:16:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/15 10:52:22 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	i + j right diagonal
	i - j left diagonal
	1) Start in the leftmost column
	2) If all queens are placed
    	return true
	3) Try all rows in the current column.
   		Do following for every tried row.
    	a) If the queen can be placed safely in this row
       		then mark this [row, column] as part of the
       		solution and recursively check if placing
       		queen here leads to a solution.
    	b) If placing the queen in [row, column] leads to
       		a solution then return true.
    	c) If placing queen doesn't lead to a solution then
       		unmark this [row, column] (Backtrack) and go to
       		step (a) to try other rows.
	4) If all rows have been tried and nothing worked,
   		return false to trigger backtracking.
*/
#include <unistd.h>
#define N 4
int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

int	is_valid_cell(int **board, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (i == x && j == y)
				continue;
			if (board[i][j] && (i == x || j == y))
				return (0);
			if(board[i][j] && (i + j == x + y || i - j == x - y))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	solve(int **board, int x, int y)
{
	int i;
	int j;

	if (x >= N - 1)
		return (1);
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (!board[i][j] && is_valid_cell(board, i, j))
			{
				board[i][j] = 1;
				if (solve(board, i + 1, j))
					return (1);
				board[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_board(int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		while (j < N)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_solution(int **board)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if(board[i][j])
			{
				c = board[i][j] + '0';
				write(1, &c, 1);
				continue;
			}
			j++;
		}
		i++;
	}
}

int ft_ten_queens_puzzle(void)
{
	int	board[N][N];
	int i;
	int n;
	int res;

	i = 0;
	res = 0;
	init_board(board);
	if (solve(board, 0, 0))
		print_solution(board);
	return (res);
}
