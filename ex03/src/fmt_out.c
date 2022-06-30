/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:09:50 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/30 12:58:25 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_err(char *program_name, char *fd_name)
{
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(fd_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_puthex(int c, int pass)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 0)
		c += 256;
	if (!pass)
		ft_putchar_fd('\\', 1);
	if (c > 15)
		ft_puthex(c / 16, 1);
	if (!pass && c < 16)
		ft_putchar_fd('0', 1);
	ft_putchar_fd(hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (' ' <= str[i] && str[i] <= '~')
			ft_putchar_fd(str[i], 1);
		else
			ft_puthex(str[i], 0);
		i++;
	}
}
