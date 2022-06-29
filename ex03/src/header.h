/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:58:12 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/29 19:04:33 by dwuthric         ###   ########.fr       */
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

int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnstr(char *str, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_puthex(int c, int pass);
void	ft_putchar_non_printable(char c);
void	special_print(char c);

void	print_err(char *program_name, char *fd_name);
void	print_offset(char *offset);
void	print_formatted(char *buf);
char	*itoh(int offset);

void	hxd(char *filepath);
#endif