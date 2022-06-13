/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:16:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 15:26:33 by dwuthric         ###   ########.fr       */
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

int	is_good_board(int *positions)
{
	int rdiagonals[10];
	int ldiagonals[10];
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		rdiagonals[i] = i + positions[i];
		ldiagonals[i] = i - positions[i];
	}
	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			if (positions[i] == positions[j] || rdiagonals[i] == rdiagonals[j])
				return (0);
			if (ldiagonals[i] == ldiagonals[j])
				return (0);
		}
	}
	return (1);
}

int	helper(int n, int *positions, int i, int total)
{

}

int ft_ten_queens_puzzle(void)
{
	int	positions[10];
	int	i;

	i = 0;
	while (i < 10)
		positions[i] = 0;
	return helper(10, positions, 0, 0);
}
