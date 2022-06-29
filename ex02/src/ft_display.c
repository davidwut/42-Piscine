/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:19:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 10:56:35 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

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

int	display_last_nb(int bcount, char *filename)
{
	int		fs;
	char	*buf;
	int		fd;

	fs = file_size(filename);
	buf = malloc(sizeof(*buf) * fs);
	if (!buf || fs <= 0)
		return (0);
	fd = open(filename, O_RDONLY);
	read(fd, buf, fs - bcount);
	read(fd, buf, bcount);
	ft_putnstr(buf, bcount);
	close(fd);
	return (1);
}
