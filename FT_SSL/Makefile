# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 18:01:44 by akikalia          #+#    #+#              #
#    Updated: 2019/04/23 00:49:02 by akikalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wextra
NAME = ft_ssl
SRCS = hash_func.c helper.c md5.c md5_init.c md5_rounds.c parse.c sha_init.c sha_process.c hash_helper.c main.c md5_helper.c md5_ops.c output.c sha_helpers.c sha_ops.c

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
