SRCS	=	main.c operations.c operations1.c operations2.c sub_operations.c sort.c sub_func.c
OBJS	=	${SRCS:.c=.o}
NAME	=	push_swap
CC	=		gcc
RM	=		rm -f
CFLAGS	=	-Wextra -Wall -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) push_swap.h Makefile
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
.PHONY: all clean fclean re
