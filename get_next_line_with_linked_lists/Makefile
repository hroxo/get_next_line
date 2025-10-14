# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 14:46:11 by hroxo             #+#    #+#              #
#    Updated: 2025/10/14 23:15:42 by hroxo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec
CC = cc
CFLAG = -Wall -Werror -Wextra -D BUFFER_SIZE=1 -g

INCLUDES = 
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(INCLUDES) $(OBJS) -o $(NAME)
	$(RM) $(OBJS)

fclean:	
	$(RM) $(NAME)

re: fclean all

val: all
	valgrind ./$(NAME)

.PHONY: all re fclean val
