/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:50:23 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 17:07:57 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *arr, int length, int (*f)(int, int))
{
	int	i;
	int	increasing;
	int	decreasing;

	increasing = 0;
	decreasing = 0;
	i = -1;
	while (++i < length - 1)
	{
		if ((*f)(arr[i], arr[i + 1]) >= 0)
			decreasing++;
		if ((*f)(arr[i], arr[i + 1]) <= 0)
			increasing++;
	}
	return (increasing == i || decreasing == i);
}
