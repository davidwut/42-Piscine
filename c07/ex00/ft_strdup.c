/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:56:19 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/21 13:12:18 by dwuthric         ###   ########.fr       */
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
	res = (char *)malloc(sizeof(*res) * (len + 1));
	len = -1;
	while (src[++len])
		res[len] = src[len];
	res[len] = 0;
	return (res);
}
