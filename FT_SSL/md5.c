/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:05:56 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/23 00:49:53 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*le(char *str)
{
	short	a;
	short	*res;
	int		i;

	i = 0;
	while (ft_strlen(str) < 8)
		str = ft_stradd(ft_strdup("0"), str);
	res = (short *)str;
	while (i < 2)
	{
		a = res[i];
		res[i] = res[3 - i];
		res[3 - i] = a;
		i++;
	}
	return ((char *)res);
}

static char	*get_final_md5(t_words *w)
{
	char	*res;

	res = ft_stradd(le(ft_uitoa_base(w->a, 16)), le(ft_uitoa_base(w->b, 16)));
	res = ft_stradd(res, le(ft_uitoa_base(w->c, 16)));
	res = ft_stradd(res, le(ft_uitoa_base(w->d, 16)));
	return (res);
}

char		*process_md5(unsigned int *m, unsigned long words)
{
	int		i;
	int		j;
	t_words	w;

	md5_init(&w);
	i = 0;
	while (i < (int)words / 16)
	{
		j = 0;
		while (j < 16)
		{
			w.x[j] = m[i * 16 + j];
			j++;
		}
		md5_reinit(&w);
		round_one(&w);
		round_two(&w);
		round_three(&w);
		round_four(&w);
		md5_save(&w);
		i++;
	}
	return (get_final_md5(&w));
}
