/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:54:55 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/14 13:14:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	res = (int *)malloc(sizeof(*res) * (max - min));
	if (res == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (max - min);
}
