/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:22:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 17:42:58 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin, void *data, int (*cmp)())
{
	t_list	*new_node;
	t_list	*current_node;
	int		size;
	int		j;

	new_node = ft_create_elem(data);
	current_node = *begin;
	size = 0;
	while (current_node && ++size && (*cmp)(current_node->data, data) < 0)
		current_node = current_node->next;
	current_node = *begin;
	j = -1;
	while (++j < size - 2)
		current_node = current_node->next;
	new_node->next = current_node->next;
	current_node->next = new_node;
}
