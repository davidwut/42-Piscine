SRC_PRE		:= srcs/
SRC			:= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:.c=.o)
HEADER		:= includes/
NAME		:= libft.a

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f
AR			:= ar rc
LIB			:= ranlib

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c -I$(HEADER) $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(LIB) $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re