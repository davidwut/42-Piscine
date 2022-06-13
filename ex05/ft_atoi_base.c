/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 11:11:54 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft5_isspace(char c)
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

int	ft5_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base_incorrect(char *base)
{
	int i;
	int j;
	if (!ft5_strlen(base) || ft5_strlen(base) == 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft5_isspace(base[i]))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int i;
	int neg;
	int baselen;

	res = 0;
	i = 0;
	neg = 1;
	if (is_base_incorrect(base))
		return (0);
	while (ft5_isspace(str[i]) && res == 0)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
	}
	return (res * neg);
}
