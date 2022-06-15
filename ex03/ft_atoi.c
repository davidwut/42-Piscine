/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:53:34 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/15 16:24:07 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = " \f\n\r\t\v";
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_helper(char *str, int i, int total, int neg)
{
	if (str[i] == '-' && total == 0)
		return (ft_atoi_helper(str, i + 1, total, neg *= -1));
	if (str[i] == '+' && total == 0)
		return (ft_atoi_helper(str, i + 1, total, neg));
	if (!('0' <= str[i] && str[i] <= '9') || !str[i])
		return (total * neg);
	return (ft_atoi_helper(str, i + 1, total * 10 + str[i] - '0', neg));
}

int	ft_atoi(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (ft_atoi_helper(str, 0, 0, 1));
}
