CC=gcc
FLAGS= -Wall -Werror -Wextra -I.
AR=ar crs
RM=rm -rf
FILES= SRCS/*.c
OBJ=$(FILES:.c=.o)
INCS= include
NAME=libft.a

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c include
	@echo "hani kan commpili$(GREEN)" $< "$(RESET)akhay sat"
	@$(CC) $(FLAGS) -c $< -o $@ -I ${INCS}

main: $(NAME) main.c
	@echo "Compiling main program"
	@$(CC) $(FLAGS) main.c -L. -lft -o test_main

clean:
	@echo "$(YELLOW)Cleaned$(RESET)"
	@$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@$(RM) $(NAME) test_main

re: fclean all
