/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:53:55 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 19:03:57 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin, void (*free_fct)(void *))
{
	t_list	*temp;

	while (begin)
	{
		(*free_fct)(begin->data);
		temp = begin->next;
		free(begin);
		begin = temp;
	}
}
