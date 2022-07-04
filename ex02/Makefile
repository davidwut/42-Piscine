SRC_PRE		:= src/
SRC			:= main.c printers.c fmt_out.c utils.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:%.c=%.o)
NAME		:= ft_tail

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