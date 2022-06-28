/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:48:55 by jwikiera          #+#    #+#             */
/*   Updated: 2022/06/28 11:48:56 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	char_printable(char c)
{
	return (c >= 32 && c <= 127);
}

int	check_chars(char empty, char wall, char full)
{
	if (!(char_printable(empty) && char_printable(wall)
			&& char_printable(full)))
		return (0);
	if (empty == wall || empty == full || wall == full)
		return (0);
	return (1);
}
