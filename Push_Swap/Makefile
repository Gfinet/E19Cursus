CC = GCC

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

MAIN = src/main.c

MAIN_OBJ =$(MAIN:.c=.o)

SRCS = 	src/push_swap.c \
		src/p_s_r.c \
		src/nlst.c \
		src/nlst2.c \
		src/nlst3.c \
		src/ps_sort.c \
		src/all_verif.c \
		src/make_less_move.c \
		src/compute_best_node.c 

OBJ = $(SRCS:.c=.o)

BONUS_SRC = bonus/checker_bonus.c \
			bonus/checker2_bonus.c \
			bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c


BONUS_OBJ = $(BONUS_SRC:.c=.o)

HEAD = push_swap.h

LIB = libftprintf.a

LIBFT = ./Printf/

NAME = push_swap

.PHONY: all clean fclean re bonus

all: $(NAME) 

$(NAME): $(OBJ) $(MAIN) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) $^ -c -o $@ 

libftprintf.a: 
	make -C $(LIBFT)
	cp $(LIBFT)$(LIB) .
	mv $(LIBFT)$(LIB) $(NAME)


clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	make -C $(LIBFT) clean
fclean: clean
	rm -f $(LIB)
	make -C $(LIBFT) fclean
	

re: fclean all

bonus: $(BONUS_OBJ) $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $^ -o checker