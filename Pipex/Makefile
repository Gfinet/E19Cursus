CC = GCC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS =  src/main_pipex.c \
		src/cmd_pipe.c \
		src/init_find_path.c \
		src/handle_error.c 

OBJ = $(SRCS:.c=.o)

BON_SRCS =  bonus/main_pipex_bonus.c \
		bonus/cmd_pipe_bonus.c \
		bonus/init_find_path_bonus.c \
		bonus/handle_error_bonus.c 

BON_OBJ = $(BON_SRCS:.c=.o)

LIBFT = ./Printf/

LIBA = libftprintf.a

LIB = $(LIBFT)$(LIBA)

NAME = pipex

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
	rm -f $(BON_OBJ)
	make -C $(LIBFT) clean
fclean: clean
	mv $(LIBA) $(LIBFT)
	rm $(NAME)
	make -C $(LIBFT) fclean
	
bonus: $(BON_OBJ) $(LIBA)
	$(CC) $(CFLAGS) $^ -o $(NAME) 

re: fclean all


