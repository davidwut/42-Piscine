/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:32 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/12 17:41:27 by dwuthric         ###   ########.fr       */
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

int	ft_atoi_base(char *str, char *base)
{
	int	res;

	res = 0;
	return (res);
}
