CC = GCC

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = main_pipex.c \
		cmd_pipe.c \
		init_find_path.c \
		handle_error.c 

LIB = $(LIBFT)libftprintf.a

LIBFT = ./Printf/

OBJ = $(SRCS:.c=.o)

NAME = pipex

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ) libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) libftprintf.a -o $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ 


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


