/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:15:48 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 10:30:56 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		*dest = src[i];
		dest++;
	}
	*dest = 0;
	return (dest);
}

int	count_total_size(int size, char **list, int sep_size)
{
	int	total_size;
	int	i;

	total_size = sep_size * -1;
	i = -1;
	while (++i < size)
		total_size += ft_strlen(list[i]) + sep_size;
	return (total_size);
}

char	*ft_strjoin(int size, char **list, char *sep)
{
	char	*res;
	int		total_size;
	int		i;

	if (size <= 0)
		return (malloc(sizeof(*res)));
	total_size = count_total_size(size, list, ft_strlen(sep));
	res = malloc(sizeof(*res) * (total_size + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		res = ft_strcpy(res, list[i]);
		if (i != size - 1)
			res = ft_strcpy(res, sep);
	}
	*res = 0;
	return (res - total_size);
}
