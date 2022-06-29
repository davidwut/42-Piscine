/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:42:57 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 11:08:26 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_atoi(argv[2]) == -1)
			print_illegaloffset(argv[0], argv[2]);
		else
			display_stdin(argv[0]);
	}
	else if (argc >= 4)
	{
		if (ft_atoi(argv[2]) == -1)
			print_illegaloffset(argv[0], argv[2]);
		else
			handle_args(argc, argv, ft_atoi(argv[2]));
	}
	return (0);
}

void	handle_args(int ac, char **av, int arg)
{
	int	i;
	int	file;

	i = 2;
	while (++i < ac)
	{
		file = open(av[i], O_RDONLY);
		if (file >= 0)
		{
			close (file);
			if (ac > 4)
				display_header(av[i], i);
			display_last_nb(arg, av[i]);
		}
		else
			print_err(av[0], av[i]);
	}
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
