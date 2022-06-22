/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:59:47 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/22 17:02:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **list, int (*cmp)(char *, char *))
{
	int		i;
	char	*temp;
	int		done;

	done = 0;
	while (!done)
	{
		i = -1;
		done = 1;
		while (list[++i + 1])
		{
			if ((*cmp)(list[i], list[i + 1]) > 0)
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				done = 0;
			}
		}
	}
}
