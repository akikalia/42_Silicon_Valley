# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akikalia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 18:09:45 by akikalia          #+#    #+#              #
#    Updated: 2019/05/12 18:01:48 by akikalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c		\
	   ft_sprintf.c		\
	   ft_memset.c		\
	   ft_strchr.c		\
	   ft_strcpy.c		\
	   ft_strcmp.c		\
	   ft_strdup.c		\
	   ft_strlen.c		\
	   ft_strncpy.c		\
	   ft_tolower.c		\
	   ft_toupper.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memccpy.c		\
	   ft_memmove.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strcat.c		\
	   ft_strncat.c		\
	   ft_strlcat.c		\
	   ft_strrchr.c		\
	   ft_strstr.c		\
	   ft_strnstr.c		\
	   ft_strncmp.c		\
	   ft_atoi.c		\
	   ft_isalpha.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_memalloc.c	\
	   ft_memdel.c		\
	   ft_strnew.c		\
	   ft_strdel.c		\
	   ft_strclr.c		\
	   ft_striter.c		\
	   ft_striteri.c	\
	   ft_strmap.c		\
	   ft_strmapi.c		\
	   ft_strequ.c		\
	   ft_strnequ.c		\
	   ft_strsub.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_itoa.c		\
	   ft_putchar.c		\
	   ft_putstr.c		\
	   ft_putendl.c		\
	   ft_putnbr.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\
	   ft_lstnew.c		\
	   ft_lstdelone.c	\
	   ft_lstdel.c		\
	   ft_lstadd.c		\
	   ft_lstiter.c		\
	   ft_lstmap.c		\
	   ft_strsplit.c	\
	   ft_isspace.c		\
	   ft_fib.c			\
	   ft_square.c		\
	   ft_power.c		\
	   ft_swap.c		\
	   ft_printf.c		\
	   print_d_i.c		\
	   print_f.c		\
	   print_o_u_x.c	\
	   print_p_s_c.c	\
	   helper.c			\
	   get_flags.c		\
	   ft_uitoa_base.c	\
	   map.c			\
	   map_helper.c		\

OBJ = ${SRCS:.c=.o}

all:$(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -c -I. $(SRCS)
	ar rcs $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean:
	/bin/rm -f $(NAME) $(OBJ)
re: fclean all
