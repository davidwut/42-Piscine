/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:12:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 14:14:20 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *arr, int length, int (*f)(int))
{
	int	*res;
	int	i;

	res = malloc(sizeof(*res) * (length));
	i = -1;
	while (++i < length)
		res[i] = (*f)(arr[i]);
	return (res);
}
