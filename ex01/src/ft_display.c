/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:19:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 19:10:16 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_strlen(char *str)
{
	int	c;

	c = -1;
	while (str[++c])
		;
	return (c);
}

void	print_err(char *program_name, char *fd_name)
{
	ft_putstr(basename(program_name), ft_strlen(basename(program_name)), STDERR_FILENO);
	ft_putstr(": ", 2, STDERR_FILENO);
	ft_putstr(fd_name, ft_strlen(fd_name), STDERR_FILENO);
	ft_putstr(": ", 2, STDERR_FILENO);
	ft_putstr(strerror(errno), ft_strlen(strerror(errno)), STDERR_FILENO);
	ft_putstr("\n", 1, STDERR_FILENO);
}

void	display_stdin(char *name)
{
	char	buf;
	int		size;

	size = read(STDIN_FILENO, &buf, 1);
	while (size != 0)
	{
		if (errno == 0)
			ft_putchar(buf, STDOUT_FILENO);
		else
		{
			print_err(name, "stdin");
			return ;
		}
		size = read(STDIN_FILENO, &buf, 1);
	}
}

int	display_file(char *filepath)
{
	int		file;
	int		size;
	char	buf[BUFF];

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		size = read(file, buf, BUFF);
		while (size != 0)
		{
			ft_putstr(buf, size, STDOUT_FILENO);
			size = read(file, buf, BUFF);
		}
		close(file);
		return (1);
	}
	return (0);
}
