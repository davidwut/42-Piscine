/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:28:03 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 12:08:16 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin, void *data_ref, int (*cmp)(),
							void (*free_fct)(void *))
{
	t_list	*current_node;
	t_list	*temp;

	current_node = *begin;
	while (current_node)
	{
		temp = current_node->next;
		if ((*cmp)(current_node->data, data_ref) == 0)
		{
			if (*begin == current_node)
				*begin = temp;
			(*free_fct)(current_node->data);
			free(current_node);
		}
		current_node = temp;
	}
}
