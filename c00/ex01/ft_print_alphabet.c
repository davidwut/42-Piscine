/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:08:58 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/08 12:09:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	i;

	i = 'a';
	while (i < 'a' + 26)
	{
		write(1, &i, 1);
		i++;
	}
}

#ifdef og

int	main(void)
{
	ft_print_alphabet();
	return (0);
}

#endif