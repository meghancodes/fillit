NAME	= fillit
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I "fillit.h"
FILES	= main.c check_tet.c new_tet.c set_tet.c map.c read_in.c tet_types.c

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
