/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:39:14 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 14:40:54 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **arr, int length, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (++i < length)
		if ((*f)(arr[i]))
			count++;
	return (count);
}
