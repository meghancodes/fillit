NAME	= fillit
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I "fillit.h"
FILES	= main.c check_table.c newtet.c

all: $(NAME)

$(NAME): srcs
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

srcs:
	mkdir srcs
clean:
	rm -rf srcs/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: srcs clean fclean re
