CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c \
			print_use.c	

NAME = libftprintf.a

OBJ = ${SRCS:.c=%.o}

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) ar rcs