/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:23:31 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 11:49:06 by dwuthric         ###   ########.fr       */
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
# define _BUF 4096
int 	ft_atoi(char *a);
void	ft_putstr(char *str);
#endif