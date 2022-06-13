/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:56:19 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 19:10:30 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*res;

	len = 0;
	while (src[len])
		len++;
	res = (char *)malloc(sizeof(*res) * len);
	len = 0;
	while (src[len])
	{
		res[len] = src[len];
		len++;
	}
	return (res);
}
