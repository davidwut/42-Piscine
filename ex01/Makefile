SRC_PRE		:= src/
SRC			:= main.c ft_putstr.c ft_display.c ft_putchar.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:.c=.o)
NAME		:= ft_cat

RM			:= rm -f
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re