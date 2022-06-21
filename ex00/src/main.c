/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:48 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/21 15:52:47 by dwuthric         ###   ########.fr       */
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
		size = 1;
		while (size != 0)
		{
			size = read(file, buf, 4096);
			ft_putstr(buf);
		}
		close(file);
	}
	else
		ft_putstr("Cannot read file.\n");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		display_file(argv[1]);
	else if (argc == 1)
		ft_putstr("File name missing.\n");
	else
		ft_putstr("Cannot read file.\n");
	return (0);
}
