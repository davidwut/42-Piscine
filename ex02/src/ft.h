/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/26 14:45:08 by dwuthric         ###   ########.fr       */
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
# include <stdlib.h>

#include <stdio.h>

# define _BUF 4096
# define INRANGE(x,a,b) a <= x && x <= b

void	ft_putstr_fd(char *str, int fd);
void	ft_putstr(char *str);
void	ft_putnstr(char *str, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	print_err(char *program_name, char *fd_name);
void	display_stdin(char *name);
int	display_last_nb(char *filepath, int bcount);
int	ft_atoi(char *str);
int	parse_arg(int ac, char **av, int *start);
int	file_size(char *filepath);
void print_illegaloffset(char **av, int start);
void print_help(char **av);

#endif