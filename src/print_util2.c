/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:28:58 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 15:44:57 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_int_grid_from_str(int **grid, t_grid_info *grid_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < grid_info->row_amount)
	{
		while (j < grid_info->row_size)
		{
			ft_putnbr(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i ++;
	}
}
