/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:02:14 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 18:10:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	flag;

	flag = 0;
	while (!flag)
	{
		i = 1;
		flag = 1;
		while (i < argc - 1)
		{
			if (argv[i] > argv[i + 1])
			{
				ft_swap(&argv[i], &argv[i + 1]);
				flag = 0;
			}
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putstr("\n");
	}
	return (0);
}
