/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:00:03 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 11:05:46 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin, void (*f)(void *), void *data_ref,
int (*cmp)())
{
	while (begin)
	{
		if ((*cmp)(begin->data, data_ref) == 0)
			(*f)(begin->data);
		begin = begin->next;
	}
}
