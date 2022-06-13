/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:57:12 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 17:20:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft09_str_is_alpha(char c)
{
	if (!('a' <= c && c <= 'z'))
		if (!('A' <= c && c <= 'Z'))
			return (0);
	return (1);
}

int	ft09_str_is_lowercase(char c)
{
	if (!('a' <= c && c <= 'z'))
		return (0);
	return (1);
}

int	ft09_str_is_printable(char c)
{
	if (!(' ' <= c && c <= '~'))
		return (0);
	return (1);
}

int	ft09_str_is_numeric(char c)
{
	if (!('0' <= c && c <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	need_cap;
	int	i;

	need_cap = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft09_str_is_alpha(str[i]))
		{
			if (need_cap && ft09_str_is_lowercase(str[i]))
				str[i] += 'A' - 'a';
			else if (!need_cap && !ft09_str_is_lowercase(str[i]))
				str[i] -= 'A' - 'a';
			need_cap = 0;
		}
		else if (ft09_str_is_printable(str[i]))
		{
			if (ft09_str_is_numeric(str[i]))
				need_cap = 0;
			else
				need_cap = 1;
		}
		i++;
	}
	return (str);
}
