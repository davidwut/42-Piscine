#ifndef HEADER_H
# define HEADER_H


# include <unistd.h> // read, write, close
# include <fcntl.h> //open, enums
# include <stdlib.h> //malloc

# define _BUF 4096

#define RED "\033[0;31m"
#define CYA "\033[0;36m"
#define NC "\033[0m"

typedef struct s_grid_info
{
    int     row_size;
    int     row_amount;
    char    empty_char;
    char    wall_char;
    char    full_char;
} s_grid_info;

int strl(char *str);
int ft_atoi(char *str);
int int_char_size(int n);

int check(char *str);

int	get_row_size(char *str, int should_clear);
int	get_real_row_count(char *str);
s_grid_info *get_grid_info(char *str);
char	**get_grid(char *str);

void    ft_putchar(char c);
void    ft_putnbr(int nb);
void    ft_putstr(char *str);
void    print_grid_info(char *str);
void	clear_grid_header(char **str);
void    print_grid_from_str(char *str);
void    print_int_grid_from_str(char *str);

int	get_file_size(char *filename);
int	count_char(char *str, char c);
char	*append_str(char str[_BUF], int size, char *buf);
char	*rd_stdin(void);
char	*rd_file(char *filename);
int	**get_int_grid(char *str);

void	solve(char *input);

#endif