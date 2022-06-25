/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:23:31 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 13:07:46 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
	unsigned int	value;
	char			*text;
}	t_map;

typedef struct s_list
{
	struct s_list	*next;
	t_map			*data;
}	t_list;

# define _BUF 4096
int 	ft_atoi(char *a);
void	ft_putstr(char *str);
t_list	*ft_create_elem(unsigned int value, char *text);
void	ft_sorted_list_insert(t_list **begin, unsigned int value, char *text, int (*cmp)());
int	cmp_map(t_map *a, t_map *b);
#endif