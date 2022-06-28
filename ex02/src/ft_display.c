/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:19:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 19:17:01 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int	display_last_nb(char *program_name, char *filepath, int bcount)
{
	int		fs;
	char	*buf;
	int		file;

	fs = file_size(filepath);
	buf = malloc(sizeof(*buf) * fs);
	file = open(filepath, O_RDONLY);
	if (errno == 21)
		return (0);
	if (file == -1)
		print_err(program_name, filepath);
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
