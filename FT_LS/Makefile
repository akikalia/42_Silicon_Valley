# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akikalia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 18:01:44 by akikalia          #+#    #+#              #
#    Updated: 2019/04/08 18:12:56 by akikalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME = ft_ls
SRCS = main.c ls_cmp.c ls_error.c ls_helper.c ls_input.c ls_print.c ls_recurs.c ls_sort.c

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
