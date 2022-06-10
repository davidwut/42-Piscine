/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:37:59 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/10 12:44:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex07_ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('a' <= str[i] && str[i] <= 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strupcase(char *str)
{
	int	offset;
	int	i;

	offset = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (ex07_ft_str_is_lowercase(str[i]))
			str[i] += offset;
		i++;
	}
	return (str);
}
