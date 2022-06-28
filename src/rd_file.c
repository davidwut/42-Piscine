/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:01:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 10:57:16 by dwuthric         ###   ########.fr       */
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
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NULL);
	buf = malloc(sizeof(*buf) * (size + 1));
	if (!buf)
		return (NULL);
	size = read(file, buf, size);
	buf[size] = 0;
	close(file);
	return (buf);
}

char	*init_magic(int *buf_size, int size)
{
	char	*res;

	if (size == -1)
		return (NULL);
	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = 0;
	*buf_size = size;
	return (res);
}

char	*rd_stdin(void)
{
	char	line[_BUF];
	char	*buf;
	int		size;
	int		line_count;
	int		buf_size;

	size = read(STDIN_FILENO, line, _BUF);
	if (!('0' <= line[0] && line[0] <= '9'))
		return (NULL);
	buf = init_magic(&buf_size, size);
	if (!buf)
		return (NULL);
	buf = append_str(line, size, buf, 0);
	if (!buf)
		return (NULL);
	line_count = ft_atoi(buf);
	while (count_char(buf, '\n') < line_count + 1)
	{
		size = read(STDIN_FILENO, line, _BUF);
		buf = append_str(line, size, buf, buf_size);
		buf_size += size;
		if (!buf)
			return (NULL);
	}
	return (buf);
}
