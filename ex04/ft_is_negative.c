/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:09:49 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 13:09:53 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	c;

	if (n < 0)
	{
		c = 'N';
		write(1, &c, 1);
	}
	else
	{
		c = 'P';
		write(1, &c, 1);
	}
}

#ifdef og

int	main(void)
{
	ft_is_negative(-5);
	ft_is_negative(0);
	ft_is_negative(42);
	return (0);
}

#endif
