/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:01:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/27 18:04:27 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*rd_file(char *filename)
{
	char	*buf;
	int		size;
	int		file;

	size = get_file_size(filename);
	if (size == -1)
		return (NULL);
	buf = malloc(sizeof(*buf) * size);
	if (!buf)
		return (NULL);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NULL);
	size = read(file, buf, size);
	return (buf);
}

char	*rd_stdin(void)
{
	char	line[_BUF];
	char	*buf;
	int		size;
	int		line_count;

	buf = malloc(1);
	if (!buf)
		return (NULL);
	buf[0] = 0;
	size = read(STDIN_FILENO, line, _BUF);
	if (!('0' <= line[0] && line[0] <= '9'))
	{
		free(buf);
		return (NULL);
	}
	buf = append_str(line, size, buf);
	line_count = ft_atoi(buf);
	while (count_char(buf, '\n') < line_count + 1)
	{
		size = read(STDIN_FILENO, line, _BUF);
		buf = append_str(line, size, buf);
	}
	return (buf);
}
