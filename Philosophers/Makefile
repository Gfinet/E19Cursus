CC = GCC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS = src/philo_main.c \
		src/action.c	\
		src/philo_init.c \
		src/utils.c

OBJ = $(SRCS:.c=.o)

NAME = philo

.PHONY: all clean fclean re

all: $(NAME)
	@echo "$(NAME) made"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@ 


clean:
	@rm -f */*.o
	@echo "clean done"

fclean: clean
	@rm $(NAME)
	@echo "fclean done"
	

re: fclean all
	@echo "make re done"

