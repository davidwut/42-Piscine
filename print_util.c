/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:57:54 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/27 10:57:59 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "header.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        nb = 147483648;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}

void ft_putstr(char *str)
{
    write(1, str, strl(str));
}

void    print_grid_info(char *str)
{
    s_grid_info *grid_info;

    grid_info = get_grid_info(str);
    ft_putstr("Grid info: ");
    ft_putstr(""CYA"row amount"NC": "RED"");
    ft_putnbr(grid_info->row_amount);
    ft_putstr(""NC", "CYA"row size"NC": "RED"");
    ft_putnbr(grid_info->row_size);
    ft_putstr(""NC", "CYA"empty char"NC": '"RED"");
    ft_putchar(grid_info->empty_char);
    ft_putstr(""NC"', "CYA"wall char"NC": '"RED"");
    ft_putchar(grid_info->wall_char);
    ft_putstr(""NC"', "CYA"full char"NC": '"RED"");
    ft_putchar(grid_info->full_char);
    ft_putstr(""NC"'\n");
    free(grid_info);
}

void    print_grid_from_str(char *str)
{
    s_grid_info *grid_info;
    char        **grid;
    int         i;
    int         j;

    grid_info = get_grid_info(str);
    grid = get_grid(str);
    i = 0;
    j = 0;
    while (i < grid_info->row_amount)
    {
        while (j < grid_info->row_size)
        {
            ft_putchar(grid[i][j]);
            j ++;
        }
        ft_putchar('\n');
        j = 0;
        i ++;
    }
    free(grid);
    free(grid_info);
}