/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:01 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/15 13:09:06 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	valid_in_base(char c, char *base_from)
{
	int i;

	i = 0;
	while (base_from[i])
		if (base_from[i++] == c)
			return (1);
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
			return (0);
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

int	adjust_for_neg(char *n, char *base_from)
{
	int	neg;
	int	i;

	neg = 1;
	i = 0;
	while (ft_isspace(n[i]))
		i++;
	while (n[i])
	{
		if (n[i] == '-' || n[i] == '+')
		{
			if (n[i] == '-')
				neg *= -1;
		}
		else if (valid_in_base(n[i], base_from))
			return (neg);
		else
			return (0);
		i++;
	}
	return (neg);
}

int	from_base_to_dec(char *n, char *base)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	total = 0;
	while (n[i])
	{
		j = 0;
		while (base[j])
		{
			if (n[i] == base[j])
				total = total * ft_strlen(base) + j;
			j++;
		}
		i++;
	}
	return (total);
}

char	*ft_clean(char *str, char *base_from)
{
	char *res;
	int	i;
	int	j;
	int	index;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	j = i;
	while (str[j])
	{
		if (!valid_in_base(str[j], base_from))
			break;
		j++;
	}
	res = (char *)malloc(sizeof(*res) * j - i + 1);
	index = 0;
	while (index < j - i)
	{
		res[index] = str[i + index];
		index++;
	}
	res[j - i] = '\0';
	return (res);
}

char	*from_dec_to_base(int n, char *base_to, int neg)
{
	char	temp[100];
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (n)
	{
		temp[99 - i] = base_to[n % ft_strlen(base_to)];
		i++;
		n /= ft_strlen(base_to);
	}
	res = (char *)malloc(sizeof(*res) * (i + 1));
	j = 0;
	if (neg == -1)
	{
		res
	}
	while (j < i)
	{
		res[j] = temp[100 - i + j];
		j++;
	}
	return (res);
}

char	*ft_convert_base(char *n, char *base_from, char *base_to)
{
	int		ret;
	char	*cleaned;
	int		neg;

	if (!is_correct_base(base_from) || !is_correct_base(base_to))
		return (NULL);
	neg = adjust_for_neg(n, base_from);
	if (!neg)
		return (NULL);
	cleaned = ft_clean(n, base_from);
	ret = from_base_to_dec(cleaned, base_from);
	return (from_dec_to_base(ret, base_to, neg));
}
