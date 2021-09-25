NAME	=   push_swap
BONUS_NAME	=	checker
HEADER  =   push_swap.h

SRCS_COMMS = $(shell ls ./commands/*.c)

SRCS_UTILS =   $(shell ls ./utils/*.c)

SRCS_SORT	=	$(shell ls ./sort/*.c)

SRCS		=   ${SRCS_UTILS} ${SRCS_COMMS} ${SRCS_SORT} push_swap.c

BONUS		=	${SRCS_UTILS} ${SRCS_COMMS} checker.c

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

CC		=   gcc

OBJS	=	$(SRCS:%.c=%.o)

BONUS_OBJS	=	$(BONUS:%.c=%.o)

ARG		=	$(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")

all:		$(NAME)

$(NAME):	${OBJS} $(HEADER)
			$(CC) -o $(NAME) ${OBJS}

bonus:		$(BONUS_NAME)

$(BONUS_NAME):	${BONUS_OBJS} $(HEADER)
				$(CC) -o $(BONUS_NAME) ${BONUS_OBJS}

%.o: 		%.c	
			$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
			$(RM) ${OBJS} ${BONUS_OBJS}

fclean:		clean
			$(RM) $(NAME) $(BONUS_NAME)

re:			fclean all

test:		
			make -s && make -s  clean && ./push_swap $(ARG)

test2:
			echo "$(ARG5)" > arg.txt
			make -s && ./push_swap $(shell cat arg.txt) | ./checker_Mac $(shell cat arg.txt)

.PHONY: clean fclean re bonus test