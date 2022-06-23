/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:08:43 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 11:10:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin, void *data_ref, int (*cmp)())
{
	while (begin)
	{
		if ((*cmp)(begin->data, data_ref) == 0)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}
