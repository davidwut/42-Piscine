/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:09:09 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/11 15:12:56 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dst, char *src, unsigned int n)
{
	unsigned int	i;
	int	dst_size;

	dst_size = 0;
	i = 0;
	while (dst[i] != '\0')
	{
		dst_size++;
		i++;
	}
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst);
}
