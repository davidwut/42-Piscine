/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:01 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/14 17:37:20 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = " \f\n\r\t\v";
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_correct_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_neg_sign(char *n, int *i)
{
	int neg;

	neg = 1;
	while (n[*i])
	{
		if (n[*i] == '-' || n[*i] == '+')
			if (n[*i] == '-')
				neg *= -1;
		*i++;
	}
	return neg;
}

int	from_base_to_dec(char n, char *base)
{
	int  i;

	i = 0;
	while (base[i])
	{
		if (n == base[i])
			return i;
		i++;
	}
	return -1;
}

char *ft_convert_base(char *n, char *base_from, char *base_to)
{
	int i;
	int j;
	int neg;
	char *res;
	int ret;

	if (!is_correct_base(base_from) || !is_correct_base(base_to))
		return (NULL);
	i = 0;
	while (ft_isspace(n[i]))
		i++;
	neg = get_neg_sign(n, &i);
	res = malloc(sizeof(*res) * ft_strlen(n));
	if (neg == -1)
		res[0] = '-';
	j = neg == -1;
	while (n[i])
	{
		ret = from_base_to_dec(n[i], base_from);
		if (ret == -1)
			return (NULL);
		res[j] = base_to[ret];
		j++;
		i++;
	}
	return (res);
}
