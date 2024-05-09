NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC = src/free.c		\
	src/inst_pr.c		\
	src/inst_rr.c		\
	src/inst_s.c		\
	src/parsing.c			\
	src/radix.c		\
	src/sort_elements.c		\
	src/utils.c		\
	src/verif.c     \
	src/main.c
DEPS = include/push_swap.h
LIBFT_DIR = libft/
LIBFT_LIB = libft/libft.a

all : $(NAME)
$(NAME) : $(LIBFT_LIB) $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re