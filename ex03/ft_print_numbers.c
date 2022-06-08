/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:00:16 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 13:00:19 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	i;

	i = '0';
	while (i < '0' + 10)
	{
		write(1, &i, 1);
		i++;
	}
}

#ifdef og

int	main(void)
{
	ft_print_numbers();
	return (0);
}

#endif
