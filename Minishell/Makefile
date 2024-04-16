NAME = minishell

INCLUDES = ./includes

LIBFT = $(INCLUDES)/libft

MY_SOURCES =	main.c		\
				# src/parsing.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

C_GREEN = \033[0;32m

C_RED = \033[0;31m

C_BLUE = \033[0;34m

C_END=\033[0m

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address -g3
LFLAGS = -L/Users/lvodak/.brew/opt/readline/lib -I/Users/lvodak/.brew/opt/readline/include -lreadline

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@make -C $(LIBFT)
	@gcc $(CFLAGS) $(LFLAGS) -o $(NAME) $(MY_OBJECTS) $(LIBFT)/libft.a
	@echo "$(C_GREEN)$(NAME) compiled with $(CFLAGS)$(C_END)"
	@echo "$(C_RED)Welcome in our mini hell$(C_END)"
	@echo "$(C_GREEN)****      ***   *******   *****    ***   ******** $(C_END)$(C_RED)               ***     ***    *********   ****        ***         $(C_END)"
	@echo "$(C_GREEN)*--**    *+-*   ***-***   *---**   *-*   ***+-*** $(C_END)$(C_RED)               *-*     *-*    *-*******   *--*        *-*         $(C_END)"
	@echo "$(C_GREEN)*-++*   **--*     *-*     *-+****  *-*      *-*   $(C_END)$(C_RED)               *-*     *-*    *-*         *--*        *-*         $(C_END)"
	@echo "$(C_GREEN)*-* ** **-*-*     *-*     *-*  *** *-*      *-*   $(C_END)$(C_RED)               *-*******-*    *-*******   *--*        *-*         $(C_END)"
	@echo "$(C_GREEN)*-* ***** *-*     *-*     *-*   ****-*      *-*   $(C_END)$(C_RED)               *-*******-*    *-*******   *--*        *-*         $(C_END)"
	@echo "$(C_GREEN)*-*  ***  *-*     *-*     *-*    **--*      *-*   $(C_END)$(C_RED)               *-*     *-*    *-*         *--*        *-*         $(C_END)"
	@echo "$(C_GREEN)*-*       *-*   ***-***   *-*     **-*   ***+-*** $(C_END)$(C_RED)               *-*     *-*    *-*******   *--*******  *-********  $(C_END)"
	@echo "$(C_GREEN)***       ***   *******   ***      ***   ******** $(C_END)$(C_RED)               ***     ***    *********   **********  **********  $(C_END)"
	@echo ""
	@echo ""
	@echo "$(C_GREEN)                                                       *****                                                        $(C_END)"  
	@echo "$(C_GREEN)                                                      ********                                                      $(C_END)"  
	@echo "$(C_GREEN)                                                ***   *-*   ***                                                     $(C_END)"  
	@echo "$(C_GREEN)                                                .**   ****   **                                                     $(C_END)"  
	@echo "$(C_GREEN)                                                 ***   *-*   ***                                                    $(C_END)"  
	@echo "$(C_GREEN)                                                  *** **-*                                                          $(C_END)"  
	@echo "$(C_GREEN)                                                   *******             $(C_END)"

%.o:	%.c
	@gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# makelibft:
# 	@make -C $(LIBFT)

clean:
	@rm -rf $(MY_OBJECTS) $(MY_OBJ_BONUS)
	@make -C $(LIBFT) clean
	@echo "$(C_RED)$(NAME) cleanse$(C_END)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a
	@echo "$(C_RED)Update: Herobrine has been removed.$(C_END)"

re: fclean all

.PHONY: all clean fclean re