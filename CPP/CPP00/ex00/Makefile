CC = c++

CFLAGS = -Wall -Wextra -Werror #-std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

NAME = megaphone


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "megaphone made"

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