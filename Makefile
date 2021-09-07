NAME	=   push_swap
HEADER  =   push_swap.h

# SRC_COM	=   s.c p.c
# SRC_COM	=   s.c p.c

SRCS_UTILS =   $(shell ls ./utils/*.c)

SRCS		=   ${SRCS_UTILS} main.c

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

CC		=   gcc

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	${OBJS} $(HEADER)
			$(CC) -o $(NAME) ${OBJS}

%.o: 		%.c	
			$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: clean fclean re