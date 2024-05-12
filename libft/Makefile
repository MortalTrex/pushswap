NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INC = ./libft_mandatory/includes/libft.h ./gnl/includes/get_next_line_bonus.h ./ft_printf/includes/ft_printf.h

PRINTF_SRCS = ft_printf/ft_printf.c \
ft_printf/ft_putchar.c \
ft_printf/ft_puthexnbr.c \
ft_printf/ft_putnbr.c \
ft_printf/ft_putptr.c \
ft_printf/ft_putstr.c \
ft_printf/ft_putunsignednbr.c \

LIBFT_SRCS = libft_core/ft_atoi.c \
libft_core/ft_bzero.c \
libft_core/ft_calloc.c \
libft_core/ft_free_split.c \
libft_core/ft_isalnum.c \
libft_core/ft_isalpha.c \
libft_core/ft_isascii.c \
libft_core/ft_isdigit.c \
libft_core/ft_isprint.c \
libft_core/ft_itoa.c \
libft_core/ft_lstadd_back.c \
libft_core/ft_lstadd_front.c \
libft_core/ft_lstclear.c \
libft_core/ft_lstdelone.c \
libft_core/ft_lstiter.c \
libft_core/ft_lstlast.c \
libft_core/ft_lstmap.c \
libft_core/ft_lstnew.c \
libft_core/ft_lstsize.c \
libft_core/ft_memchr.c \
libft_core/ft_memcmp.c \
libft_core/ft_memcpy.c \
libft_core/ft_memmove.c \
libft_core/ft_memset.c \
libft_core/ft_only_space.c \
libft_core/ft_putchar_fd.c \
libft_core/ft_putendl_fd.c \
libft_core/ft_putnbr_fd.c \
libft_core/ft_putstr_fd.c \
libft_core/ft_split.c \
libft_core/ft_strchr.c \
libft_core/ft_strdup.c \
libft_core/ft_striteri.c \
libft_core/ft_strjoin.c \
libft_core/ft_strlcat.c \
libft_core/ft_strlcpy.c \
libft_core/ft_strlen.c \
libft_core/ft_strmapi.c \
libft_core/ft_strncmp.c \
libft_core/ft_strnstr.c \
libft_core/ft_strrchr.c \
libft_core/ft_strtrim.c \
libft_core/ft_substr.c \
libft_core/ft_tolower.c \
libft_core/ft_toupper.c \

SRC = $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
