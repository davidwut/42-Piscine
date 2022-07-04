/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:48:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/20 11:46:47 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcpy(char *src)
{
	unsigned int	i;
	char			*res;

	res = malloc(sizeof(*res) * (ft_strlen(src) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (src[++i])
		res[i] = src[i];
	res[i] = 0;
	return (res);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;

	res = malloc(sizeof(*res) * (ac + 1));
	if (!res)
		return (NULL);
	res[ac].size = 0;
	res[ac].str = 0;
	res[ac].copy = 0;
	i = -1;
	while (++i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = ft_strcpy(av[i]);
		res[i].copy = ft_strcpy(av[i]);
	}
	return (res);
}
