/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:16:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/16 17:37:50 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	i + j right diagonal
	i - j left diagonal
*/

#include <unistd.h>
#define N 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid_cell(int *board, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == y || x + y == i + board[i] || x - y == i - board[i])
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int queens, int *res)
{
	int	i;
	int	j;

	if (queens == N)
	{
		j = 0;
		*res += 1;
		while (j < N)
			ft_putchar(board[j++] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = 0;
		while (i < N)
		{
			if (is_valid_cell(board, queens, i))
			{
				board[queens] = i;
				solve(board, queens + 1, res);
			}
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[N];
	int	i;
	int	res;

	i = 0;
	while (i < N)
		board[i++] = -1;
	res = 0;
	solve(board, 0, &res);
	return (res);
}
