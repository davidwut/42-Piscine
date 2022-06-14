/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:16:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/14 11:52:34 by dwuthric         ###   ########.fr       */
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

int	check_valid_board(int x, int y, int *board, int n)
{
	int i;

	i = 1;
	while (i < x)
	{
		if (board[i] == y || i + y - x = board[i] || board[i] == y + x - i)
		{
			y++;
			i = 0;
		}
	}
	if (y > n)
		return 0;
	else
		return y;
}

int ft_ten_queens_puzzle(void)
{
	int	board[51];
	int n;
	int	i;
	int ret;

	n = 10;
	i = 1;
	while (i <= n)
		board[i] = 1;
	i = 1;
	while (1)
	{
		while (i <= n)
		{
			ret = check(i, board[i]);
			if (ret != 0)
				board[i] = ret;
			else
			{
				board[i] = 1;
				board[i - 1] = board[i = 1] + 1;
				i = i - 2;
			}
		}
		i++;
	}
}
