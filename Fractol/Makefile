CC = GCC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS = main_fractol.c \
	mandelbrot.c\
	esc_handle.c

LIB = $(LIBFT)libftprintf.a

LIBFT = ./Printf/


OBJ = $(SRCS:.c=.o)

NAME = fractol

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ) libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) libftprintf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 


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


