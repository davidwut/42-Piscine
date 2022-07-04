/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:15:39 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 09:47:25 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin)
{
	t_list	*last;
	t_list	*temp;
	t_list	*current_node;

	last = 0;
	current_node = *begin;
	while (current_node)
	{
		temp = current_node;
		current_node = current_node->next;
		temp->next = last;
		last = temp;
	}
	*begin = last;
}
