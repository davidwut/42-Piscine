/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:46:47 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 15:06:53 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_reverse_fun(t_list *begin)
{
	t_list	*current_node;
	int		size;
	int		i;
	int		j;
	void	*temp;

	current_node = begin;
	size = 0;
	while (current_node && ++size)
		current_node = current_node->next;
	current_node = begin;
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		current_node = begin;
		while (current_node && current_node->next && j < size - 1)
		{
			temp = current_node->data;
			current_node->data = current_node->next->data;
			current_node->next->data = temp;
			current_node = current_node->next;
			j++;
		}
	}
}
