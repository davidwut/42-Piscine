/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:27:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 11:41:06 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <sys/stat.h>
#include <fcntl.h>

t_map	*build_dict(char *filepath)
{
	int		file;
	ssize_t	size;
	char	buf[_BUF];

	file = open(filepath, O_RDONLY);
	if (file != 1)
	{
		size = read(file, buf, _BUF);
		while (size != 0)
		{

			size = read(file, buf, _BUF);
		}
	}
	else
		ft_putstr("Dict Error\n");
}

// for testing
int main(int argc, char **argv)
{
	t_map	*dict;

	if (argc == 2)
		dict = build_dict(argv[1]);
	else
		dict = build_dict("../language_packs/numbers_en.dict");
	return (0);
}
