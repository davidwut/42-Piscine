/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:06:29 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:11 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex12_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{

}
