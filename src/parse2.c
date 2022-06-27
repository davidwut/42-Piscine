/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:18:59 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 13:19:01 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_int_for_char(char c, s_grid_info *grid_info)
{
    if (c == grid_info->empty_char)
        return (1);
    else
        return (0);
}

int	**get_int_grid(char *str)
{
	int 		**res;
	s_grid_info	*grid_info;
	int			i;
	int			j;
	
	grid_info = get_grid_info(str);
	res = malloc(sizeof(char*) * grid_info->row_amount);
	clear_grid_header(&str);
	i = 0;
	j = 0;
	while (i < grid_info->row_amount)
	{
		res[i] = malloc(sizeof(char) * grid_info->row_size);
		while (j < grid_info->row_size)
		{
			res[i][j] = get_int_for_char(str[0], grid_info);
			j ++;
			str ++;
		}
		j = 0;
		i ++;
		str ++;
	}
	free(grid_info);
	return (res);
}