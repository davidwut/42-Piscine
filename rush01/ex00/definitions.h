/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:11:23 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 17:29:04 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

typedef enum e_datatypes {
	INPUT,
	BOARD,
	BOARD_CPY
}	t_datatypes;

typedef enum e_views {
	COL_UP,
	COL_DOWN,
	ROW_LEFT,
	ROW_RIGHT
}	t_views;

int	g_size;
int	g_sum;
int	g_done;
#endif