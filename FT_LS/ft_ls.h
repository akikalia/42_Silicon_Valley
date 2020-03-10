/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:31:43 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/08 18:15:48 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <stdint.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <sys/stat.h>
# include <errno.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# define SIX_MONTHS (15552000)

typedef struct	s_file
{
	struct stat	*stt;
	char		type;
	char		*path;
	char		*name;
}				t_file;

typedef struct	s_flag
{
	int			a;
	int			r;
	int			l;
	int			r_upper;
	int			t;
}				t_flag;

typedef struct	s_node
{
	t_list		*prev;
	t_list		*curr;
	t_list		*temp;
}				t_node;

int				cmp_(void*a, void*b);
int				cmpr(void*a, void*b);
int				cmpt(void*a, void*b);
int				cmprt(void*a, void*b);
void			ft_lstadd_sorted(t_list **alst,
int (*cmp)(void*a, void*b), t_file *s, int flag);
void			print_all(const char *str, t_flag *f);
void			print_list(t_list *head, t_flag *f);
void			print_usage(char c);
void			print_not_dir(const char *str);
void			print_denied(const char *str);
int				link_len(t_list *head);
char			*ft_straddfree(char *a, char *b);
void			free_all(t_list *head);
t_list			*read_dir(const char *str, t_flag *f, DIR **curr);
t_flag			*parse_flags(t_list **head, int size, char **str);
void			print_invalid(t_list **head);
int				get_lstat(t_file *file);
void			add_file_sorted(t_list **alst, char *name, int flag);
int				get_lstat(t_file *file);

#endif
