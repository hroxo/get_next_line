# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 15:40:21 by hroxo             #+#    #+#              #
#    Updated: 2025/10/21 15:53:28 by hroxo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_me
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=100000

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

SRC_B = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) main.c -o $(NAME)
	rm -rf *.o

bonus: $(NAME) $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) main.c -o $(NAME)
	rm -rf *.o

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
.PHONY: all bonus val
