/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:19:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/24 15:03:10 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_err(char *program_name, char *fd_name)
{
	ft_putstr(basename(program_name), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(fd_name, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

void	display_stdin(char *name)
{
	char	buf;

	while (read(STDIN_FILENO, &buf, 1) != 0)
	{
		if (errno == 0)
			(void) errno;
		else
		{
			print_err(name, "stdin");
			return ;
		}
	}
}

int	display_file(char *filepath)
{
	int		file;
	char	buf[_BUF];

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		while (read(file, buf, _BUF) != 0)
			ft_putstr(buf, STDOUT_FILENO);
		close(file);
		return (1);
	}
	return (0);
}
