CC = GCC

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = push_swap.c \
		p_s_r.c \
		nlst.c \
		nlst2.c

HEAD = push_swap.h		

LIB = $(LIBFT)libftprintf.a

LIBFT = ./Printf/

OBJ = $(SRCS:.c=.o)

NAME = push_swap

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ) libftprintf.a
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) $^ -c -o $@ 

libftprintf.a: 
	make -C $(LIBFT)
	cp $(LIB) .
	mv $(LIB) $(NAME)

clean:
	rm -f *.o
	make -C $(LIBFT) clean
fclean: clean
	rm -f *.a
	make -C $(LIBFT) fclean
	

re: fclean all
