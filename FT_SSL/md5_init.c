/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:15:53 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 06:16:05 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_init(t_words *w)
{
	w->a = 0x67452301;
	w->b = 0xefcdab89;
	w->c = 0x98badcfe;
	w->d = 0x10325476;
}

void	md5_reinit(t_words *w)
{
	w->aa = w->a;
	w->bb = w->b;
	w->cc = w->c;
	w->dd = w->d;
}

void	md5_save(t_words *w)
{
	w->a = w->a + w->aa;
	w->b = w->b + w->bb;
	w->c = w->c + w->cc;
	w->d = w->d + w->dd;
}
