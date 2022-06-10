/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:46:02 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/10 13:10:43 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex08_ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int	offset;
	int	i;

	offset = 'A' - 'a';
	i = 0;
	while (str[i] != '\0')
	{
		if (ex08_ft_str_is_uppercase(&str[i]))
			str[i] += offset;
		i++;
	}
	return (str);
}
