/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:07:07 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 19:13:22 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (begin)
	{
		if (i++ == n)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}
