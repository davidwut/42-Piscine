/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:41:04 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 12:11:46 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int n, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (!power)
		return (1);
	res = 1;
	while (power--)
		res *= n;
	return (res);
}
