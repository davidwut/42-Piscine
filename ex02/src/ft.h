/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 10:57:41 by dwuthric         ###   ########.fr       */
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

void	handle_args(int ac, char **av, int arg);
int		ft_atoi(char *str);
int		file_size(char *filename);
int		display_last_nb(int bcount, char *filename);
void	display_stdin(char *name);
void	display_header(char *name, int i, int ac);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnstr(char *str, int n);
void	print_err(char *program_name, char *fd_name);
void	print_illegaloffset(char *program_name, char *err);
int		ft_strlen(char *str);
#endif