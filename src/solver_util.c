/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:57:43 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 13:42:44 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b, int c)
{
	int	temp;

	temp = a;
	if (temp > b)
		temp = b;
	if (temp > c)
		temp = c;
	return (temp);
}
