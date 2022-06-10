/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:57:12 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/10 13:48:56 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	need_cap;
	int	correction;
	int	i;

	need_cap = 1;
	correction = 'A' - 'a';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			need_cap = 1;
		else if ('0' <= str[i] && str[i] <= '9')
			need_cap = 0;
		if (need_cap)
		{
			if ('a' <= str[i] && str[i] <= 'z')
			{
				str[i] += correction;
				need_cap = 0;
			}
		}
		i++;
	}
	return (str);
}
