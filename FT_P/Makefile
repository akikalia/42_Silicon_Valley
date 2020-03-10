# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 18:01:44 by akikalia          #+#    #+#              #
#    Updated: 2019/06/25 13:20:51 by akikalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wextra -Werror
NAME_SRVR = server
NAME_CLNT = client
SRCS_SRVR = ./sources/server_main.c ./sources/mutural.c
SRCS_CLNT = ./sources/client_main.c ./sources/mutural.c

all:
	make -C ./libft/
	mkdir $(NAME_SRVR)
	mkdir $(NAME_CLNT)
	mkdir $(NAME_CLNT)1
	$(CC) $(CFLAGS) -I. $(SRCS_SRVR) ./libft/libft.a -o ./$(NAME_SRVR)/$(NAME_SRVR)
	$(CC) $(CFLAGS) -I. $(SRCS_CLNT) ./libft/libft.a -o ./$(NAME_CLNT)/$(NAME_CLNT)
	$(CC) $(CFLAGS) -I. $(SRCS_CLNT) ./libft/libft.a -o ./$(NAME_CLNT)1/$(NAME_CLNT)1

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -Rr $(NAME_SRVR)
	/bin/rm -Rr $(NAME_CLNT)
	/bin/rm -Rr $(NAME_CLNT)1
re: fclean all
