CC = GCC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS =  src/main_pipex.c \
		src/cmd_pipe.c \
		src/init_find_path.c \
		src/handle_error.c 

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
	rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	rm -f $(LIB)
	rm $(NAME)
	make -C $(LIBFT) fclean
	

re: fclean all


