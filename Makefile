# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhorn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 12:19:16 by mhorn             #+#    #+#              #
#    Updated: 2017/02/09 12:40:53 by mhorn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= fillit
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I "fillit.h" -L./libft -lft
FILES	= main2.c check_tet.c new_tet.c set_tet.c map.c read_in.c tet_types.c solver.c
LIBFT_DIR = ./libft

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: srcs clean fclean re
