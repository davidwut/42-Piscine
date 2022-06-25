/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:21:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 12:28:42 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

t_list	*ft_create_elem(t_map data)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	return (node);
}

void	ft_sorted_list_insert(t_list **begin, t_map data, int (*cmp)())
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