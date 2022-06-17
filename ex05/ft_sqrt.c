/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:20:09 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/17 12:15:13 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647

typedef unsigned long long	t_ull;

int	sqrt_helper(t_ull n, t_ull left, t_ull right)
{
	t_ull	mid;

	if (left > right)
		return (0);
	mid = (left + right) / 2;
	if (mid * mid == n)
		return (mid);
	if (mid * mid < n)
		return (sqrt_helper(n, mid + 1, right));
	else
		return (sqrt_helper(n, left, mid - 1));
}

int	ft_sqrt(int n)
{
	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	return (sqrt_helper((t_ull)n, 2, MAX_INT));
}
