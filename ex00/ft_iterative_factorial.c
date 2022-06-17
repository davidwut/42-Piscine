/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:24:36 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/17 10:25:33 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int n)
{
	int	res;

	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	res = 1;
	while (n)
		res *= (n--);
	return (res);
}
