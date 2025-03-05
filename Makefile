CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_SRC_FILES = ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isspace.c ft_getchar.c\
				  ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c get_next_line.c \
				  ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
				  ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
				  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c \
				  ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_printf.c ft_putptr.c ft_putuint.c ft_atoi.c

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

.PHONY:clean
