/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:25:50 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/20 13:49:04 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	next_token(char *str, char *charset)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (charset[j] == str[i])
				return (i);
	}
	return (i);
}

int	listlen(char **list)
{
	int	c;

	c = 0;
	while (list[c])
		c++;
	return (c);
}

char	**append_str(char *str, int from, int to, char **list)
{
	char	**res;
	int		i;
	int		j;

	if (to - from <= 1)
		return (list);
	res = malloc(sizeof(*res) * (listlen(list) + 2));
	i = -1;
	while (++i < listlen(list))
		res[i] = list[i];
	res[i + 1] = list[i];
	res[i] = malloc(sizeof(*res[i]) * (to - from + 1));
	j = 0;
	while (j < to - from)
	{
		res[i][j] = str[from + j];
		j++;
	}
	res[i][j] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		last;
	int		next;

	res = malloc(sizeof(*res));
	res[0] = 0;
	last = 0;
	while (1)
	{
		next = last + next_token(str + last, charset);
		res = append_str(str, last, next, res);
		last = next + 1;
		if (next == ft_strlen(str))
			break ;
	}
	return (res);
}
