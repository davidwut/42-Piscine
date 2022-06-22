/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:23:35 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 16:06:30 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	addition(int a, int b);
void	substraction(int a, int b);
void	division(int a, int b);
void	multiplication(int a, int b);
void	modulo(int a, int b);

#endif