# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 18:01:44 by akikalia          #+#    #+#              #
#    Updated: 2019/05/12 18:09:21 by akikalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
NAME = minishell
SRCS = main.c array_ops.c builtins.c input.c

all: $(NAME)
$(NAME):
	make -C ./libft/
	$(CC) $(CFLAGS) -I. $(SRCS) ./libft/libft.a -o $(NAME)
clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)
re: fclean all
