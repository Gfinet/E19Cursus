CC = GCC

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_ltoa_base.c \
		ft_putendl_fd.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_putnbr_fd.c

LIB = libft.a


OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIB)

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) -I . -c $(SRCS)


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

