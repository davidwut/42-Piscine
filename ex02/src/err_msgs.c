/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:13:44 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 12:13:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_err(char *program_name, char *fd_name)
{
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(fd_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_illegaloffset(char **av, int start)
{
	ft_putstr_fd(basename(av[0]), STDERR_FILENO);
	ft_putstr_fd(": illegal offset -- ", STDERR_FILENO);
	if (start == 1)
		ft_putstr_fd(av[1] + 2, STDERR_FILENO);
	else
		ft_putstr_fd(av[2], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_help(char **av)
{
	ft_putstr_fd(basename(av[0]), STDERR_FILENO);
	ft_putstr_fd(": illegal option -- ", STDERR_FILENO);
	ft_putstr_fd(av[1] + 1, STDERR_FILENO);
	ft_putstr_fd("\nusage: ", STDERR_FILENO);
	ft_putstr_fd(basename(av[0]), STDERR_FILENO);
	ft_putstr_fd(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n",
		STDERR_FILENO);
}
