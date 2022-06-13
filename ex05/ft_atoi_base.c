/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/13 18:39:15 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isspace(char c)
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

int	strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base_incorrect(char *base)
{
	int	i;
	int	j;

	if (strlen(base) <= 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || isspace(base[i]))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int convert_num(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
    		return (i);
        i++;
    }
    return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	neg;
    int	ret;

	res = 0;
	i = 0;
	neg = 1;
	if (is_base_incorrect(base))
		return (0);
	while (isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i])
	{
		ret = convert_num(str[i++], base);
		if (ret = -1)
    		return (0);
		res = res * strlen(base) + ret;
	}
	return (res * neg);
}
