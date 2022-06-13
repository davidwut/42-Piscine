/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:09:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 13:14:38 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int n)
{
	int	i;

	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	i = 2;
	while (i <= n / 2 + 1)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int n)
{
	while (!ft_is_prime(n + 1))
		n++;
	return (n + 1);
}
