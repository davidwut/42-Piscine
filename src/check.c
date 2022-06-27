/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:02:46 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/26 17:02:47 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "header.h"

int get_empty(char **str, char *empty)
{
    if ((*str)[0])
    {
        *empty = (*str)[0];
        (*str) += 1;
    }
    else
        return (0);
    return (1);
}

int get_wall(char **str, char *wall)
{
    if ((*str)[0])
    {
        *wall = (*str)[0];
        (*str) += 1;
    }
    else
        return (0);
    return (1);
}

/* Returns length of the first line if valid, otherwise 0 */
/* Also modifies row_size, empty, and wall */
int check_header(char *str, int *row_amount, char *empty, char *wall)
{
    *row_amount = ft_atoi(str);
    if (!*row_amount)
        return (0);
    str += int_char_size(*row_amount);
    if (!get_empty(&str, empty) || !get_wall(&str, wall))
        return (0);
    if (!str[0] || (str[0] && str[0] == '\n'))
        return (0);
    str ++;
    if (!str[0] || (str[0] && str[0] != '\n'))
        return (0);
    return (int_char_size(*row_amount) + 4);
}

/* Checks the grid itself */
int check_grid(char *str, char empty, char wall)
{
    int current_row_count;
    int row_size;

    row_size = get_row_size(str, 0);
    current_row_count = 0;
    while (str[0])
    {
        if (str[0] != '\n' && str[0] != empty && str[0] != wall)
            return (0);
        if (str[0] == '\n' && current_row_count != row_size)
            return (0);
        if (current_row_count == row_size && str[0] != '\n')
            return (0);
        if (str[0] == '\n')
            current_row_count = 0;
        else
            current_row_count ++;
        str ++;
    }
    return (current_row_count == 0);
}

int check(char *str)
{
    int     row_amount;
    char    empty;
    char    wall;

    if (check_header(str, &row_amount, &empty, &wall))
        str += check_header(str, &row_amount, &empty, &wall);
    else
        return (0);
    if (row_amount != get_real_row_count(str))
        return (0);
    return (check_grid(str, empty, wall));
}