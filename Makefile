NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MAIN = src/main.c
SRC = $(wildcard src/*.c)

LIBFT_DIR = libft/
LIBFT_LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRC)
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
