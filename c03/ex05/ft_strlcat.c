/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:51:18 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 09:57:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_len;
	unsigned int	src_len;

	i = ft_strlen(dst);
	j = 0;
	dst_len = i;
	src_len = ft_strlen(src);
	if (size < 1)
		return (size + src_len);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size < dst_len)
		return (size + src_len);
	else
		return (dst_len + src_len);
}
