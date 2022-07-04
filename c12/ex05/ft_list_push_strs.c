/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:26:49 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 18:49:19 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	t_list	*new_node;
	int		i;

	if (size <= 0)
		return (NULL);
	head = ft_create_elem(strs[0]);
	i = 0;
	while (++i < size)
	{
		new_node = ft_create_elem(strs[i]);
		new_node->next = head;
		head = new_node;
	}
	return (head);
}
