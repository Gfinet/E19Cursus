CC = GCC

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

MAIN = main.c

MAIN_OBJ =$(MAIN:.c=.o)

SRCS = 	push_swap.c \
		p_s_r.c \
		nlst.c \
		nlst2.c \
		nlst3.c \
		ps_sort.c \
		all_verif.c \
		make_less_move.c \
		compute_best_node.c \
		guess_second.c

OBJ = $(SRCS:.c=.o)

BONUS_SRC = checker.c \
			get_next_line.c \
			get_next_line_utils.c


BONUS_OBJ = $(BONUS_SRC:.c=.o)

HEAD = push_swap.h

LIB = $(LIBFT)libftprintf.a

LIBFT = ./Printf/

NAME = push_swap

.PHONY: all clean fclean re bonus

all: $(NAME) 

$(NAME): $(OBJ) $(MAIN) libftprintf.a
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

bonus: $(BONUS_OBJ) $(OBJ) libftprintf.a
	$(CC) $(CFLAGS) $^ -o checker