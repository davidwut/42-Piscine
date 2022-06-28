/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:28:58 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/28 12:21:21 by dwuthric         ###   ########.fr       */
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

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, strl(str));
}

void	print_final_char(int x, t_grid_info *info)
{
	if (x == -1)
		ft_putchar(info->full_char);
	else if (x == 0)
		ft_putchar(info->wall_char);
	else
		ft_putchar(info->empty_char);
}

void	print_final_grid(int **map, t_grid_info *info)
{
	int	i;
	int	j;
	int	row;
	int	col;

	row = info->row_amount;
	col = info->row_size;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (USE_COLOR)
				print_final_char_color(map[i][j], info);
			else
				print_final_char(map[i][j], info);
		}
		ft_putchar('\n');
	}
}
