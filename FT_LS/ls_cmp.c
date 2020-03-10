/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:38:57 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/07 21:53:29 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				cmp_(void *a, void *b)
{
	char		*s1;
	char		*s2;

	s1 = ((t_file*)a)->name;
	s2 = ((t_file*)b)->name;
	return (ft_strcmp(s1, s2));
}

int				cmpr(void *a, void *b)
{
	char		*s1;
	char		*s2;

	s1 = ((t_file*)a)->name;
	s2 = ((t_file*)b)->name;
	return (ft_strcmp(s2, s1));
}

int				cmpt(void *a, void *b)
{
	t_file		*f1;
	t_file		*f2;
	int			i;

	f1 = (t_file *)a;
	f2 = (t_file *)b;
	i = f2->stt->st_mtime - f1->stt->st_mtime;
	if (i == 0)
		return (cmp_(a, b));
	else
		return (i);
}

int				cmprt(void *a, void *b)
{
	t_file		*f1;
	t_file		*f2;
	int			i;

	f1 = (t_file *)a;
	f2 = (t_file *)b;
	i = f1->stt->st_mtime - f2->stt->st_mtime;
	if (i == 0)
		return (cmpr(a, b));
	else
		return (i);
}
