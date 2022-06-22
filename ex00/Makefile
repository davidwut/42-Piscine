SRC_PRE		:= src/
SRC			:= main.c ft_putstr.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:.c=.o)
NAME		:= ft_display_file

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re