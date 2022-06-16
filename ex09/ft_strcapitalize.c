/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:57:12 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/16 12:49:08 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_is_printable(char c)
{
	if (!(' ' <= c && c <= '~'))
		return (0);
	return (1);
}

int	str_is_numeric(char c)
{
	if (!('0' <= c && c <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		need_cap;
	int		i;
	char	c;

	need_cap = 1;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (need_cap && 'a' <= c && c <= 'z')
			str[i] -= 32;
		else if (!need_cap && 'A' <= c && c <= 'Z')
			str[i] += 32;
		if (('a' <= c && c <= 'z')
			|| ('0' <= c && c <= '9')
			|| ('A' <= c && c <= 'Z'))
			need_cap = 0;
		else
			need_cap = 1;
		i++;
	}
	return (str);
}
