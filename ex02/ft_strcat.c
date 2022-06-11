/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:40:08 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/11 15:06:21 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	dst_size;

	dst_size = 0;
	i = 0;
	while (dst[i] != '\0')
	{
		dst_size++;
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst);
}
