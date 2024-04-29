CC = GCC

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRCS = 	src/push_swap.c \
		src/p_s_r.c \
		src/nlst.c \
		src/nlst2.c \
		src/nlst3.c \
		src/ps_sort.c \
		src/all_verif.c \
		src/make_less_move.c \
		src/compute_best_node.c \
		src/free.c \
		src/main.c

OBJ = $(SRCS:.c=.o)

BONUS_SRC = bonus/checker_bonus.c \
			bonus/checker2_bonus.c \
			bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c


BONUS_OBJ = $(BONUS_SRC:.c=.o)

HEAD = push_swap.h

LIBFT = ./Printf/

LIBA = libftprintf.a

LIB = $(LIBFT)$(LIBA)

NAME = push_swap

.PHONY: all clean fclean re bonus

all: $(NAME) 

$(NAME): $(OBJ) $(LIBA)
	$(CC) $(CFLAGS) $^ -o $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ 


libftprintf.a:
	make -C $(LIBFT)
	cp $(LIB) .
	mv $(LIB) $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBA)
	make -C $(LIBFT) fclean
	
re: fclean all
