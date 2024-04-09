CC = GCC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address


SRCS = src/main_fractol.c \
	src/mandelbrot.c\
	src/handle_event.c

LIB = $(LIBFT)libftprintf.a

LIBFT = ./Printf/


OBJ = $(SRCS:.c=.o)

NAME = fractol

ifeq ($(hostname),"MacBook-Air-de-Guylian.local")
	CFLAGS="-Wall -Wextra -Werror -D WIN_WIDTH=2560 -D WIN_HEIGHT=1664"
echo $(hostname)
endif

.PHONY: all clean fclean re

all: $(NAME)
	

$(NAME): $(OBJ) libftprintf.a mlx/libmlx.a
	@$(CC) $(CFLAGS) $^ -framework OpenGL -framework AppKit -o $(NAME)
	@echo "fractol made"
%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

mlx/libmlx.a:
	@make -C mlx/
	@echo "library mlx made"

libftprintf.a:
	@make -C $(LIBFT)
	@cp $(LIB) .
	@mv $(LIB) $(NAME)


clean:
	@rm -f */*.o
	@make -C $(LIBFT) clean
	@echo "clean done"
fclean: clean
	@rm -f *.a
	@make -C $(LIBFT) fclean
	@rm $(NAME)
	@echo "fclean done"
	

re: fclean all
	@echo "make re done"

