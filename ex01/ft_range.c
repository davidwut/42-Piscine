/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:13:27 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 19:26:29 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(*res) * (max - min));
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
