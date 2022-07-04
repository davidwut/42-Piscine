/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:35:21 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/28 13:25:11 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*char_to_str(char c)
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	res[0] = c;
	res[1] = 0;
	return (res);
}

void	print_final_char_color(int x, t_grid_info *info)
{
	char	*full_str;
	char	*wall_str;

	full_str = malloc(sizeof(char) * (strl(CYA) + strl(NC) + 2));
	full_str[0] = 0;
	ft_strncat(full_str, CYA, strl(CYA));
	ft_strncat(full_str, char_to_str(info->full_char), 2);
	ft_strncat(full_str, NC, strl(NC));
	wall_str = malloc(sizeof(char) * (strl(RED) + strl(NC) + 2));
	wall_str[0] = 0;
	ft_strncat(wall_str, RED, strl(RED));
	ft_strncat(wall_str, char_to_str(info->wall_char), 2);
	ft_strncat(wall_str, NC, strl(NC));
	if (x == -1)
		ft_putstr(full_str);
	else if (x == 0)
		ft_putstr(wall_str);
	else
		ft_putchar(info->empty_char);
	free(full_str);
	free(wall_str);
}
