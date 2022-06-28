/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/28 16:06:46 by dwuthric         ###   ########.fr       */
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

# define _BUF 4096

void	handle_args(int ac, char **av);
void	two_args(char **av);
void	n_args(int ac, char **av);
int		ft_atoi(char *str);
int		file_size(char *filepath);
int		display_last_nb(char *filepath, int bcount);
void	display_stdin(char *name);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnstr(char *str, int n);
void	print_err(char *program_name, char *fd_name);
void	print_illegaloffset(char *program_name, char *err);
void	print_help(char *program_name);
int		ft_strlen(char *str);
#endif