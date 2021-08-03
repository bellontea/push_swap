NAME = push_swap.a
LIB = libft.a

PATH_LIB = ./libft/

HEADERS = ./push_swap.h ./libft/libft.h
HDR_INC = -I ./ -I ./libft/

C_FLAGS = -Wall -Wextra -Werror -c

SRC = main.c				
SOURCES = ${SRC}
OBJS = ${SOURCES:.c=.o} $(addprefix $(PATH_LIB), $(LIB_OBG))

RM = rm -rf

%.o : %.c $(HEADERS)
	gcc $(C_FLAGS) $(HDR_INC) $< -o $@

all: run_libft 
	gcc $(C_FLAGS) $(HDR_INC) $(OBJS) -L $(PATH_LIB) -lft -o $(LIB)

run_libft:
	@make -C $(PATH_LIB)

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $(NAME) $(OBJS) $(HEADERS)

clean:
	$(RM) $(OBJS)
	@make -C $(PATH_LIB) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(PATH_LIB) fclean

re: fclean all
