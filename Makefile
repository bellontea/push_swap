NAME	=   push_swap
HEADER  =   push_swap.h

SRCS_COMMS = $(shell ls ./commands/*.c)

SRCS_UTILS =   $(shell ls ./utils/*.c)

SRCS		=   ${SRCS_UTILS} ${SRCS_COMMS} $(shell ls ./*.c)

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

CC		=   gcc

OBJS	=	$(SRCS:%.c=%.o)

ARG		=	$(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")

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

test:		
			make -s && make -s  clean && ./push_swap $(ARG)

.PHONY: clean fclean re