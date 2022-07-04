/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:10:44 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 17:19:39 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

void	fill_colup(int ***data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][COL_UP][i] == g_size)
		{
			j = -1;
			while (++j < g_size)
				data[BOARD][j][i] = j + 1;
		}
		if (data[INPUT][COL_UP][i] == 1)
			data[BOARD][0][i] = g_size;
	}
}

void	fill_coldown(int ***data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][COL_DOWN][i] == g_size)
		{
			j = -1;
			while (++j < g_size)
				data[BOARD][g_size - 1 - j][i] = j + 1;
		}
		if (data[INPUT][COL_DOWN][i] == 1)
			data[BOARD][g_size - 1][i] = g_size;
	}
}

void	fill_rowleft(int ***data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][ROW_LEFT][i] == g_size)
		{
			j = -1;
			while (++j < g_size)
				data[BOARD][i][j] = j + 1;
		}
		if (data[INPUT][ROW_LEFT][i] == 1)
			data[BOARD][i][0] = g_size;
	}
}

void	fill_rowright(int ***data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		if (data[INPUT][ROW_RIGHT][i] == g_size)
		{
			j = -1;
			while (++j < g_size)
				data[BOARD][i][g_size - 1 - j] = j + 1;
		}
		if (data[INPUT][ROW_RIGHT][i] == 1)
			data[BOARD][i][g_size - 1] = g_size;
	}
}
