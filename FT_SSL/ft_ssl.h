/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:54:39 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 06:54:40 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# define S_TRUE 100
# define S_NEXT 101
# define ISDIR -900
# define MD5 0
# define SHA256 1
# define SHA224 2

typedef struct		s_flag
{
	int				p;
	int				q;
	int				r;
	int				hash_alg;
}					t_flag;

typedef struct		s_file
{
	char			*name;
	char			*content;
	int				fd;
	int				s_flag;
}					t_file;

typedef struct		s_words
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	aa;
	unsigned int	bb;
	unsigned int	cc;
	unsigned int	dd;
	unsigned int	ee;
	unsigned int	ff;
	unsigned int	gg;
	unsigned int	hh;
	unsigned int	x[16];
	unsigned int	(*func)(unsigned int, unsigned int, unsigned int);
}					t_words;

char				*md5(char *str);
char				*sha256(char *str);
char				*sha224(char *str);
char				*process_sha(unsigned int *m, unsigned long words, int p);
unsigned long		append(char **str, int i);
unsigned long		appendsha(char **str);
int					get_hash(char *str, t_flag *f);
void				ft_lstappend(t_list **head, t_list *new);
void				usage(int i, char *str);
unsigned int		rotate_right(unsigned int x, unsigned int s);
unsigned int		ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int		maj(unsigned int x, unsigned int y, unsigned int z);
unsigned int		bsig0(unsigned int x);
unsigned int		bsig1(unsigned int x);
unsigned int		ssig0(unsigned int x);
unsigned int		ssig1(unsigned int x);
void				reinit(t_words *w);
void				save(t_words *w);
char				*ap_z(char *str);
unsigned int		convert(char *str, int size);
void				print_all(t_list *head, t_flag *f);
char				*hash(t_flag *flags, char *str);
t_file				*get_file(char *str, int s_flag);
int					get_flag(char *str, t_flag *f, int *flag);
unsigned int		rotate_right(unsigned int x, unsigned int s);
void				init(t_words *w, int p);
unsigned int		f(unsigned int x, unsigned int y, unsigned int z);
unsigned int		g(unsigned int x, unsigned int y, unsigned int z);
unsigned int		h(unsigned int x, unsigned int y, unsigned int z);
unsigned int		i(unsigned int x, unsigned int y, unsigned int z);
void				round_one(t_words *w);
void				round_two(t_words *w);
void				round_three(t_words *w);
void				round_four(t_words *w);
void				abcd(t_words *w,
		unsigned int k, unsigned int s, unsigned int i);
void				dabc(t_words *w,
		unsigned int k, unsigned int s, unsigned int i);
void				cdab(t_words *w,
		unsigned int k, unsigned int s, unsigned int i);
void				bcda(t_words *w,
		unsigned int k, unsigned int s, unsigned int i);
unsigned int		rotate_left(unsigned int x, unsigned int s);
void				md5_save(t_words *w);
void				md5_reinit(t_words *w);
void				md5_init(t_words *w);
char				*process_md5(unsigned int *m, unsigned long words);

#endif
