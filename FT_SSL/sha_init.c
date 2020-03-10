/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:40:30 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 05:00:33 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		init_sha256(t_words *w)
{
	w->a = 0x6a09e667;
	w->b = 0xbb67ae85;
	w->c = 0x3c6ef372;
	w->d = 0xa54ff53a;
	w->e = 0x510e527f;
	w->f = 0x9b05688c;
	w->g = 0x1f83d9ab;
	w->h = 0x5be0cd19;
}

static void		init_sha224(t_words *w)
{
	w->a = 0xc1059ed8;
	w->b = 0x367cd507;
	w->c = 0x3070dd17;
	w->d = 0xf70e5939;
	w->e = 0xffc00b31;
	w->f = 0x68581511;
	w->g = 0x64f98fa7;
	w->h = 0xbefa4fa4;
}

void			reinit(t_words *w)
{
	w->aa = w->a;
	w->bb = w->b;
	w->cc = w->c;
	w->dd = w->d;
	w->ee = w->e;
	w->ff = w->f;
	w->gg = w->g;
	w->hh = w->h;
}

void			save(t_words *w)
{
	w->a = w->a + w->aa;
	w->b = w->b + w->bb;
	w->c = w->c + w->cc;
	w->d = w->d + w->dd;
	w->e = w->e + w->ee;
	w->f = w->f + w->ff;
	w->g = w->g + w->gg;
	w->h = w->h + w->hh;
}

void			init(t_words *w, int p)
{
	if (p == SHA256)
		init_sha256(w);
	else
		init_sha224(w);
}
