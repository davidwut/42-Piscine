/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:02:14 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/14 12:31:59 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, char *str2)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	while (*str2)
	{
		write(1, str2, 1);
		str2++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	char	*temp;

	flag = 0;
	while (!flag)
	{
		i = 1;
		flag = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				flag = 0;
			}
			i++;
		}
	}
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++], "\n");
	return (0);
}
