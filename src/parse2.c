/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:18:59 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 16:18:02 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_int_for_char(char c, t_grid_info *grid_info)
{
	return (c == grid_info->empty_char);
}

int	**get_int_grid(char *str, t_grid_info *grid_info)
{
	int 		**res;
	int			i;
	int			j;

	res = malloc(sizeof(*res) * grid_info->row_amount);
	clear_grid_header(&str);
	i = -1;
	while (++i < grid_info->row_amount)
	{
		res[i] = malloc(sizeof(*res[i]) * grid_info->row_size);
		j = -1;
		while (++j < grid_info->row_size)
		{
			res[i][j] = get_int_for_char(*str, grid_info);
			str++;
		}
		str++;
	}
	return (res);
}