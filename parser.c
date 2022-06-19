/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:02:10 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/19 17:21:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "definitions.h"

int	count(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		size++;
		if (str[i + 1] == 0)
			return (size);
		else if (str[i + 1] != ' ')
			return (-1);
		i += 2;
	}
	return (size);
}

int	**convert(char *input)
{
	int	**res;
	int	i_res;
	int	i_input;
	int	val;

	res = malloc(sizeof(*res) * g_size);
	i_res = 0;
	i_input = 0;
	while (input[i_input])
	{
		if (i_res % g_size == 0)
			res[i_res / g_size] = malloc(sizeof(int *) * g_size);
		val = input[i_input] - '0';
		if (val <= 0 || val > g_size)
			return (NULL);
		res[i_res / g_size][i_res % 4] = val;
		if (input[i_input + 1] == 0)
			break ;
		i_input += 2;
		i_res++;
	}
	return (res);
}

void	set_sum(void)
{
	int	i;
	int	sum;

	i = 1;
	sum = 0;
	while (i <= g_size)
	{
		sum += i;
		i++;
	}
	g_sum = sum;
}

int	**parse(int argc, char **argv)
{
	int	**res;
	int	size;

	if (argc != 2)
		return (NULL);
	size = count(argv[1]);
	if (size % 4 != 0 || size < 12)
		return (NULL);
	g_size = size / 4;
	set_sum();
	res = convert(argv[1]);
	return (res);
}
