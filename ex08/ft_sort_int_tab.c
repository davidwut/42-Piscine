/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:13:49 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/10 10:39:39 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ex08_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *arr, int size)
{
	int	i;
	int	flag;

	flag = 0;
	while (!flag)
	{
		i = 0;
		flag = 1;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ex08_swap(&arr[i], &arr[i + 1]);
				flag = 0;
			}
			i++;
		}
	}
}
