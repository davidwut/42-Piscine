/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:13:44 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 15:14:07 by dwuthric         ###   ########.fr       */
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

void	print_illegaloffset(char *program_name, char *err)
{
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(": illegal offset -- ", STDERR_FILENO);
	ft_putstr_fd(err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_help(char *program_name)
{
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(": option require an argument -- c\nusage: ", 2);
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", 2);
}
