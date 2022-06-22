/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:36:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 17:51:10 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin, void *data)
{
	t_list	*head;

	if (*begin)
	{
		head = ft_create_elem(data);
		head->next = *begin;
		*begin = head;
	}
	else
		*begin = ft_create_elem(data);
}
