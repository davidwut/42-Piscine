/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:02:10 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/18 15:37:10 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*append_int(char c, int *list)
{
	int	*res;
	int	i;
	int	list_len;

	list_len = 0;
	while (list[list_len] != -1)
		list_len++;
	res = malloc(sizeof(*res) * (list_len + 2));
	i = 0;
	while (i < list_len)
	{
		res[i] = list[i];
		i++;
	}
	res[i] = c - '0';
	res[i + 1] = -1;
	free(list);
	return (res);
}

int	*convert(char *str, int *n)
{
	int	i;
	int	*res;
	int	space_last;

	space_last = 1;
	i = 0;
	res = malloc(sizeof(*res));
	res[0] = -1;
	while (str[i])
	{
		if (space_last && '0' <= str[i] && str[i] <= '9')
		{
			n++;
			res = append_int(str[i], res);
			space_last = 0;
		}
		else if (!space_last && !('0' <= str[i] && str[i] <= '0'))
			space_last = 1;
		else
			return (NULL);
		i++;
	}
	return (res);
}

int	*parse(int argc, char **argv, int *n)
{
	int *res;

	if (argc != 2)
		return (NULL);
	res = convert(argv[1], n);
	if (res == NULL || *n == -1)
		return (NULL);
	return (res);
}
