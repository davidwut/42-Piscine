/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:28:58 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 13:29:00 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    print_int_grid_from_str(char *str)
{
    s_grid_info *grid_info;
    int        **grid;
    int         i;
    int         j;

    grid_info = get_grid_info(str);
    grid = get_int_grid(str);
    i = 0;
    j = 0;
    while (i < grid_info->row_amount)
    {
        while (j < grid_info->row_size)
        {
            ft_putnbr(grid[i][j]);
            j ++;
        }
        ft_putchar('\n');
        j = 0;
        i ++;
    }
    free(grid);
    free(grid_info);
}