/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:15:43 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 18:23:40 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*current_node;

	current_node = *begin_list;
	while (current_node->next)
		current_node = current_node->next;
	new_node = ft_create_elem(data);
	new_node->next = NULL;
	current_node->next = new_node;
}
