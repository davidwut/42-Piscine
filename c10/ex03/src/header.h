/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:58:12 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/30 13:21:15 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

char	*itoh(int offset);
void	print_offset(char *offset);
void	print_line(int offset, char *buf, int size);
int		get_file_size(char *filepath);
void	hxd(char *filepath);

void	print_err(char *program_name, char *fd_name);
void	ft_puthex(int c, int pass);
void	ft_putstr_non_printable(char *str);

int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnstr(char *str, int n);
int		ft_strcmp(char *a, char *b, int size);
void	ft_putchar(char c, int n);

#endif