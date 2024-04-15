CC = GCC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address


SRCS = src/main_fractol.c \
	src/mandelbrot.c\
	src/handle_event.c \
	src/zoom.c

OBJ = $(SRCS:.c=.o)

BON_SRCS = bonus/main_fractol_bonus.c \
	bonus/mandelbrot_bonus.c\
	bonus/handle_event_bonus.c \
	bonus/zoom_bonus.c

BON_OBJ = $(BON_SRCS:.c=.o)

LIB = $(LIBFT)libftprintf.a

LIBFT = ./Printf/

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
	@rm -f $(OBJ)
	@rm -f $(BON_OBJ)
	@make -C $(LIBFT) clean
	@echo "clean done"
fclean: clean
	@rm -f libftprintf.a
	@make -C $(LIBFT) fclean
	@rm $(NAME)
	@echo "fclean done"
	

bonus : $(BON_OBJ) libftprintf.a mlx/libmlx.a
	@$(CC) $(CFLAGS) $^ -framework OpenGL -framework AppKit -o $(NAME)
	@echo "fractol bonus made"

re: fclean all
	@echo "make re done"

