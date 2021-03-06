/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:01 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 19:25:38 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_isspace(char c);
int		is_correct_base(char *base);
int		valid_in_base(char c, char *base_from);

long long	from_base_to_dec(char *n, char *base)
{
	int			i;
	int			j;
	long long	total;

	i = -1;
	total = 0;
	while (n[++i] && valid_in_base(n[i], base))
	{
		j = -1;
		while (base[++j])
			if (n[i] == base[j])
				total = total * ft_strlen(base) + j;
	}
	return (total);
}

char	*ft_clean(char *str, int *neg)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*neg *= -1;
	return (str + i);
}

char	*prepend_num(char *str, char c)
{
	char	*res;
	int		i;

	res = malloc(sizeof(*res) * (ft_strlen(str) + 2));
	res[0] = c;
	i = 0;
	while (++i < ft_strlen(str) + 1)
		res[i] = str[i - 1];
	res[i] = 0;
	free(str);
	return (res);
}

char	*from_dec_to_base(long long n, char *base_to, int neg)
{
	char	*res;

	res = malloc(sizeof(*res) * 1);
	res[0] = 0;
	while (n)
	{
		res = prepend_num(res, base_to[n % ft_strlen(base_to)]);
		n /= ft_strlen(base_to);
	}
	if (neg == -1)
		res = prepend_num(res, '-');
	return (res);
}

char	*ft_convert_base(char *n, char *base_from, char *base_to)
{
	long long	ret;
	char		*cleaned;
	int			neg;

	if (!is_correct_base(base_from) || !is_correct_base(base_to))
		return (NULL);
	neg = 1;
	cleaned = ft_clean(n, &neg);
	ret = from_base_to_dec(cleaned, base_from);
	return (from_dec_to_base(ret, base_to, neg));
}
