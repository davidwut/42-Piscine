/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:46:02 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 17:53:48 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	data_swap(t_list *node)
{
	void	*temp;

	temp = node->data;
	node->data = node->next->data;
	node->next->data = temp;
}

void	sort_list(t_list **begin, int (*cmp)())
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
				data_swap(next_node);
				sorted = 0;
			}
			next_node = next_node->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin1, t_list *begin2, int (*cmp)())
{
	t_list	*list1;

	list1 = *begin1;
	while (list1->next)
		list1 = list1->next;
	if (begin2)
		list1->next = begin2;
	sort_list(begin1, cmp);
}
