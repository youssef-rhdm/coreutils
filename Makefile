CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_SRC_FILES = ft_convert.c ft_is_x.c ft_stack.c ft_mem.c ft_str_utils.c ft_strlength.c get_next_line.c ft_math.c ft_lst_utils.c  ft_put_fd.c ft_printf.c

LIBFT_OBJ_FILES = $(LIBFT_SRC_FILES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(LIBFT_OBJ_FILES)
	ar rc $(NAME) $^

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(LIBFT_OBJ_FILES)

fclean : clean
	$(RM) *.a

re: fclean all

.PHONY: clean
