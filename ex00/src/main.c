/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:48 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 18:49:13 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <sys/stat.h>
#include <fcntl.h>

void	display_file(char *filepath)
{
	int		file;
	int		size;
	char	buf[4097];

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		size = read(file, buf, 4096);
		while (size != 0)
		{
			ft_putstr(buf, size, STDOUT_FILENO);
			size = read(file, buf, 4096);
		}
		close(file);
	}
	else
		ft_putstr("Cannot read file.\n", 19, STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		display_file(argv[1]);
	else if (argc == 1)
		ft_putstr("File name missing.\n", 20, STDERR_FILENO);
	else
		ft_putstr("Too many arguments.\n", 21, STDERR_FILENO);
	return (0);
}
