# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 18:01:44 by akikalia          #+#    #+#              #
#    Updated: 2019/06/27 15:13:58 by akikalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -g -Wextra -Werror
NAME = ft_nm
SRCS = nm_main.c fat64.c fat32.c mach32.c mach64.c endian.c

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
