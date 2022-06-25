SRC_PRE		:= src/
SRC			:= main.c ft_atoi.c ft_strlen.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:%.c=%.o)
NAME		:= rush-02

RM			:= rm -f
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)