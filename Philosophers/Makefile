CC = GCC

CFLAGS = -Wall -Wextra -Werror -pthread #-g3 -fsanitize=thread

SRCS = src/philo_main.c		\
		src/action.c		\
		src/philo_init.c	\
		src/check_philo.c	\
		src/utils.c

OBJ = $(SRCS:.c=.o)

NAME = philo

.PHONY: all clean fclean re exe

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(NAME) made"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

exe: all clean

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean done"
	

re: fclean all
	@echo "make re done"

