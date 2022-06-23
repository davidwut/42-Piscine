/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/23 15:31:34 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define BUFF 30000

void	ft_putstr(char *str, int fd);
void	ft_putchar(char c, int fd);
void	print_err(char *program_name, char *fd_name);
void	display_stdin(char *name);
int		display_file(char *filepath);

#endif