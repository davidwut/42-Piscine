/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:35:21 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 17:35:23 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *char_to_str(char c)
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	res[0] = c;
	res[1] = 0;
	return (res);
}

void	print_final_char_color(int x, t_grid_info *info)
{
	if (x == -1)
		ft_putchar(info->full_char);
	else if (x == 0)
		ft_putchar(info->wall_char);
	else
		ft_putchar(info->empty_char);
}