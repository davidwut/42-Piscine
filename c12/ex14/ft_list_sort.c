/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:50:14 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 13:44:56 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_data(t_list *node)
{
	void	*temp;

	temp = node->data;
	node->data = node->next->data;
	node->next->data = temp;
}

void	ft_list_sort(t_list **begin, int (*cmp)())
{
	t_list	*next_node;
	int		sorted;

	sorted = 0;
	while (!sorted)
	{
		next_node = *begin;
		sorted = 1;
		while (next_node->next)
		{
			if ((*cmp)(next_node->data, next_node->next->data) > 0)
			{
				swap_data(next_node);
				sorted = 0;
			}
			next_node = next_node->next;
		}
	}
}
