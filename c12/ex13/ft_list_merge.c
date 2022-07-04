/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:11:26 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 12:25:46 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin1, t_list *begin2)
{
	t_list	*list1;

	list1 = *begin1;
	while (list1->next)
		list1 = list1->next;
	if (begin2)
		list1->next = begin2;
}
