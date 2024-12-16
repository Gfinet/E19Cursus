CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address 

SRC =	main.cpp	\
		bsp.cpp		\
		Point.cpp	\
		Fixed.cpp	\
		Line.cpp	\
		Triangle.cpp

OBJ = $(SRC:.cpp=.o)

NAME = BSP


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "test ready"

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean done"
	

re: fclean all
	@echo "make re done"