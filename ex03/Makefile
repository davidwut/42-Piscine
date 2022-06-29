SRCS_PRE		:= src/
SRC				:= main.c utils.c fmt_out.c dumper.c
SRCS			:= $(addprefix $(SRCS_PRE),$(SRC))
OBJS			:= $(SRCS:%.c=%.o)
NAME			:= ft_hexdump

RM				:= rm -rf
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

clean:			$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re