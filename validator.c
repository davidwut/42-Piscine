/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:16:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 13:47:11 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

int	valid_colup(int ***data, int index)
{
	int	view;
	int sum;
	int	highest;
	int	i;
	int	temp;

	view = 0;
	sum = 0;
	highest = 0;
	i = -1;
	while (++i < g_size)
	{
		temp = data[BOARD][i][index];
		sum += temp;
		if (temp > highest)
		{
			highest = temp;
			view++;
		}
	}
	return (sum == g_sum && view == data[INPUT][COL_UP][index]);
}

int	valid_coldown(int ***data, int index)
{
	int	view;
	int sum;
	int	highest;
	int	i;
	int	temp;

	view = 0;
	sum = 0;
	highest = 0;
	i = -1;
	while (++i < g_size)
	{
		temp = data[BOARD][g_size - 1 - i][index];
		sum += temp;
		if (temp > highest)
		{
			highest = temp;
			view++;
		}
	}
	return (sum == g_sum && view == data[INPUT][COL_DOWN][index]);
}

int	valid_rowleft(int ***data, int index)
{
	int	view;
	int sum;
	int	highest;
	int	i;
	int	temp;

	view = 0;
	sum = 0;
	highest = 0;
	i = -1;
	while (++i < g_size)
	{
		temp = data[BOARD][index][i];
		sum += temp;
		if (temp > highest)
		{
			highest = temp;
			view++;
		}
	}
	return (sum == g_sum && view == data[INPUT][ROW_LEFT][index]);
}

int	valid_rowright(int ***data, int index)
{
	int	view;
	int sum;
	int	highest;
	int	i;
	int	temp;

	view = 0;
	sum = 0;
	highest = 0;
	i = -1;
	while (++i < g_size)
	{
		temp = data[BOARD][index][g_size - 1 - i];
		sum += temp;
		if (temp > highest)
		{
			highest = temp;
			view++;
		}
	}
	return (sum == g_sum && view == data[INPUT][ROW_RIGHT][index]);
}

int	valid_solution(int ***data)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		if (!(valid_colup(data, i) &&
			valid_coldown(data, i) &&
			valid_rowleft(data, i) &&
			valid_rowright(data, i)))
			return (0);
		i++;
	}
	return (1);
}
