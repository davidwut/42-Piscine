SRC_PRE		:= src/
SRC			:= check.c parse.c parse2.c print_util.c print_util2.c rd_file.c util.c util2.c main.c solver.c solver_util.c freeer.c color_fun.c
SRCS		:= $(addprefix $(SRC_PRE),$(SRC))
OBJS		:= $(SRCS:%.c=%.o)
NAME		:= bsq

RM			:= rm -f
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re