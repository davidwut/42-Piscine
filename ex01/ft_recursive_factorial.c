/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:35:01 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/17 10:28:41 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int n)
{
	if (n < 0)
		return (0);
	if (n == 0 || n == 1)
		return (1);
	return (n * ft_recursive_factorial(n - 1));
}
