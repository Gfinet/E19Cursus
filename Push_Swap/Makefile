CC = GCC

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRCS = 	main.c \
		push_swap.c \
		p_s_r.c \
		nlst.c \
		nlst2.c \
		nlst3.c \
		ps_sort.c \
		all_verif.c \
		make_less_move.c \
		compute_best_node.c

HEAD = push_swap.h		

LIB = libftprintf.a

LIBFT = ./Printf/

OBJ = $(SRCS:.c=.o)

NAME = push_swap

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LIB) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) $^ -c -o $@ 

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
	

re: fclean all
