/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:45:56 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/08 15:19:32 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	lstat_failure(t_node *n, char *path, t_list **head)
{
	if (!ft_strcmp("Bad file descriptor", strerror(errno)))
		ft_printf("ft_ls: %s: Bad file descriptor\n", path);
	else
		ft_printf("ft_ls: %s: No such file or directory\n", path);
	if (n->prev)
		n->prev->next = n->curr->next;
	else
		*head = n->curr->next;
	n->temp = n->curr;
	n->curr = n->curr->next;
	free(n->temp->content);
	n->temp->content = NULL;
	free(n->temp);
	n->temp = NULL;
}

void		print_invalid(t_list **head)
{
	t_node		n;
	struct stat	st;
	char		*path;

	n.prev = NULL;
	n.curr = *head;
	while (n.curr)
	{
		path = (char *)(n.curr->content);
		if (lstat(path, &st) == -1)
			lstat_failure(&n, path, head);
		else
		{
			n.prev = n.curr;
			n.curr = n.curr->next;
		}
	}
}

static void	flag_init(t_flag **f, int *flag, int *i)
{
	*f = malloc(sizeof(t_flag));
	*i = 1;
	*flag = 1;
	(*f)->r_upper = 0;
	(*f)->r = 0;
	(*f)->l = 0;
	(*f)->a = 0;
	(*f)->t = 0;
}

static void	get_flag(t_flag *f, char c)
{
	if (c == 'R')
		f->r_upper++;
	else if (c == 'r')
		f->r++;
	else if (c == 'l')
		f->l++;
	else if (c == 'a')
		f->a++;
	else if (c == 't')
		f->t++;
}

t_flag		*parse_flags(t_list **head, int size, char **str)
{
	int		i;
	int		n;
	int		flag;
	t_flag	*f;

	flag_init(&f, &flag, &i);
	while (i < size)
	{
		if (str[i][0] != '-' || !str[i][1])
			break ;
		n = 1;
		while (str[i][n])
		{
			if (flag && (str[i][n] == 'R' || str[i][n] == 'r' ||
			str[i][n] == 'l' || str[i][n] == 'a' || str[i][n] == 't'))
				get_flag(f, str[i][n]);
			else
				print_usage(str[i][n]);
			n++;
		}
		i++;
	}
	while (i != size)
		add_file_sorted(head, str[i++], 1);
	return (f);
}
