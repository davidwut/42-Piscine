/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:49:41 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 16:50:33 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

char	*advance(char *str, char *charset)
{
	while (*str && in_charset(*str, charset))
		str++;
	return str;
}

char	*advance_range(char *str, char a, char b)
{
	while (a <= *str && *str <= b)
		str++;
	return str;
}
int	ft_isspace(char c)
{
	int		i;
	char	*set;

	i = -1;
	set = " \f\n\r\t\v";
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

t_ll	not_atoi(char *str, int *i)
{
	t_ll	total;
	int				neg;

	total = 0;
	neg = 1;
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	while (str[*i] && (str[*i] == '-' || str[*i] =='+'))
	{
		if (str[*i] == '-')
			neg *= -1;
		(*i)++;
	}
	while (str[*i] && '0' <= str[*i] && str[*i] <= '9')
	{
		total = total * 10 + str[*i] - '0';
		(*i)++;
	}
	return (total * neg);
}
