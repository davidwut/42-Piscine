/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:48 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/21 17:03:02 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <sys/stat.h>
#include <fcntl.h>

void	display_file(char *filepath)
{
	int		file;
	ssize_t	size;
	char	buf[4096];

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		size = read(file, buf, 4096);
		while (size != 0)
		{
			ft_putstr(buf, STDOUT_FILENO);
			size = read(file, buf, 4096);
		}
		close(file);
	}
	else
		ft_putstr("Cannot read file.\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		display_file(argv[1]);
	else if (argc == 1)
		ft_putstr("File name missing.\n", STDERR_FILENO);
	else
		ft_putstr("Too many arguments.\n", STDERR_FILENO);
	return (0);
}
