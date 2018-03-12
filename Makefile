# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2017/11/30 10:33:39 by obenazzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, lem-in, clean, fclean, re

CC = gcc -Wall -Wextra -Werror
NAME = lem-in
LFT_PATH = ./ft_printf/
SRC_NAME = get_next_line/get_next_line.c int_parsing.c error.c queue.c \
pr_malloc.c parse_nodes.c list_utils.c adj_list.c anthill_printing.c \
reverse_queue.c skip_comments.c move_ants.c breadth_first_search.c valid_last_line.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(OBJ_NAME) lem_in.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
