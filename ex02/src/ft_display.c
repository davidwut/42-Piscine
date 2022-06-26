/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:19:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/26 14:47:28 by dwuthric         ###   ########.fr       */
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
	ft_putstr_fd(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", STDERR_FILENO);
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

int	display_last_nb(char *filepath, int bcount)
{
	int		fs;
	char	*buf;
	int		file;

	fs = file_size(filepath);
	buf = malloc(sizeof(*buf) * fs);
	file = open(filepath, O_RDONLY);
	if (!buf || fs <= 0 || file == -1)
		return (0);
	read(file, buf, fs - bcount);
	read(file, buf, bcount);
	close(file);
	ft_putnstr(buf, bcount);
	return (1);
}

int	file_size(char *filepath)
{
	int		size;
	int		total_size;
	int		file;
	char	buf[_BUF];

	total_size = 0;
	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		size = read(file, buf, _BUF);
		while (size != 0)
		{
			total_size += size;
			size = read(file, buf, _BUF);
		}
		close(file);
		return (total_size);
	}
	return (-1);
}
