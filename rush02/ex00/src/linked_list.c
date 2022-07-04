/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:21:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 17:57:55 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

t_list	*ft_create_elem(t_ll value, char *text)
{
	t_list	*node;
	t_map	*data;

	node = malloc(sizeof(*node));
	data = malloc(sizeof(*data));
	data->value = value;
	data->text = text;
	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	return (node);
}

int	cmp_map(t_map *a, t_map *b)
{
	return (a->value >= b->value);
}

void	data_swap(t_list *node)
{
	void	*temp;

	temp = node->data;
	node->data = node->next->data;
	node->next->data = temp;
}
void	ft_list_push_back(t_list **begin_list, t_ll value, char *text)
{
	t_list	*new_node;
	t_list	*current_node;

	current_node = *begin_list;
	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
		new_node = ft_create_elem(value, text);
		new_node->next = NULL;
		current_node->next = new_node;
	}
	else
		*begin_list = ft_create_elem(value, text);
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
				data_swap(next_node);
				sorted = 0;
			}
			next_node = next_node->next;
		}
	}
}
