CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3

SRC =	main.cpp			\
		convertType.cpp		\
		detectType.cpp		\
		detectType.cpp		\
		ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ScalarConverter


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