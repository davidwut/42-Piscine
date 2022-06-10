/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:57:12 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/10 13:04:36 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	found_space;
	int	correction;
	int	i;

	found_space = 1;
	correction = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (found_space)
		{
			if ('a' <= str[i] && str[i] <= 'z')
			{
				str[i] += correction;
				found_space = 0;
			}
		}
		else if (str[i] == ' ')
		{
			found_space = 1;
		}
		i++;
	}
	return (str);
}
