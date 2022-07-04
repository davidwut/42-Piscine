/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:12:13 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 11:47:03 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	valid_in_base(char c, char *base_from)
{
	int	i;

	i = -1;
	while (base_from[++i])
		if (base_from[i] == c)
			return (1);
	return (0);
}

int	is_correct_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = -1;
	while (base[++i])
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
	}
	return (1);
}
