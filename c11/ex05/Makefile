SRC_PRE		:= src/
SRC			:= main.c ft_atoi.c ft_putnbr.c ft_putchar.c ft_putstr.c operations.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:.c=.o)
NAME		:= do-op

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re