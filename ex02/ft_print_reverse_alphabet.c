/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:55:22 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 12:55:25 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	i;

	i = 122;
	while (i > 122 - 26)
	{
		write(1, &i, 1);
		i--;
	}
}

#ifdef og

int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}

#endif