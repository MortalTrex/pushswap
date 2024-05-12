NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = libft
LIBFT = libft.a
#LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)

INC = -Iinclude -Ilibft

SRC = src/free.c \
      src/inst_pr.c \
      src/inst_rr.c \
      src/inst_s.c \
      src/parsing.c \
      src/radix.c \
      src/sort_elements.c \
      src/utils.c \
      src/verif.c \
      src/main.c \
      src/linked_list.c

OBJ_DIR = build
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

all:  $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@echo "Making Libft"
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) $(INC) -lft
	@echo "push_swap ready."

clean:
	@echo Cleaning up object files	
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re