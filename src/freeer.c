/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:09:21 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 16:14:03 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	superfree(int ***map, t_grid_info **info)
{
	int	i;
	int	row;

	row = (*info)->row_amount;
	i = -1;
	while (++i < row)
		free((*map)[i]);
	free((*map));
	free((*info));
}
