/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:48:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/17 15:13:19 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcpy(char *src)
{
	unsigned int	i;
	char 			*res;

	i = -1;
	res = malloc(sizeof(*res) * ft_strlen(src));
	while (src[++i])
		res[i] = src[i];
	return (res);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	unsigned int		i;

	res = malloc(sizeof(*res) * ac + 1);
	res[ac].size = ac;
	res[ac].str = 0;
	res[ac].copy = 0;
	i = -1;
	while (++i < ac)
	{
		res[i].size = ac;
		res[i].str = ft_strcpy(av[i]);
		res[i].copy = ft_strcpy(av[i]);
	}
	return (res);
}
