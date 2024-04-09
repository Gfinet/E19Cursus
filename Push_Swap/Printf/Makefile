CC = GCC

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_make_list.c \
	ft_ltoa_base.c \
	ft_strndup.c \
	ft_plst.c \
	ft_modif.c

LIBA = libft.a

LIBFT = ./libft/

LIB = $(LIBFT)$(LIBA)

OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ) libft.a
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ 


libft.a: 
	make -C $(LIBFT)
	cp $(LIB) .
	mv $(LIB) $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	mv $(LIBA) $(LIBFT)
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	

re: fclean all


