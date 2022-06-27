/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:40:33 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 09:40:35 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "header.h"

void	clear_grid_header(char **str)
{
	while ((*str)[0] != '\n')
	{
		(*str)++;
	}
	(*str)++;
}

int	get_real_row_count(char *str)
{
	int	i;

	i = 0;
	while (str[0])
	{
		if (str[0] == '\n')
			i ++;
		str ++;
	}
	return (i);
}

int	get_row_size(char *str, int should_clear)
{
	int	i;

	if (should_clear)
		clear_grid_header(&str);
	i = 0;
	while (str[0] != '\n')
	{
		i ++;
		str ++;
	}
	return (i);
}

s_grid_info	*get_grid_info(char *str)
{
	s_grid_info	*res;

	res = malloc(sizeof(res));
	if (!res)
		return (0);
	res->row_amount = ft_atoi(str);
	res->row_size = get_row_size(str, 1);
	str += int_char_size(ft_atoi(str));
	res->empty_char = str[0];
	res->wall_char = str[1];
	res->full_char = str[2];
	return (res);
}

/* Returns 0 if fails to malloc */
char	**get_grid(char *str)
{
	char		**res;
	s_grid_info	*grid_info;
	int			i;
	int			j;

	grid_info = get_grid_info(str);
	res = malloc(sizeof (char*) * grid_info->row_amount);
	clear_grid_header(&str);
	i = 0;
	j = 0;
	while (i < grid_info->row_amount)
	{
		res[i] = malloc(sizeof(char) * grid_info->row_size);
		while (j < grid_info->row_size)
		{
			res[i][j] = str[0];
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
