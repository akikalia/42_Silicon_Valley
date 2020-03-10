/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:00:24 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/23 00:52:47 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	g_k[] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
	0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138,
	0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
	0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f,
	0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

char				*get_final_sha(t_words *w, int p)
{
	char			*res;

	res = ft_stradd(ap_z(ft_uitoa_base(w->a, 16)),
			ap_z(ft_uitoa_base(w->b, 16)));
	res = ft_stradd(res, ap_z(ft_uitoa_base(w->c, 16)));
	res = ft_stradd(res, ap_z(ft_uitoa_base(w->d, 16)));
	res = ft_stradd(res, ap_z(ft_uitoa_base(w->e, 16)));
	res = ft_stradd(res, ap_z(ft_uitoa_base(w->f, 16)));
	res = ft_stradd(res, ap_z(ft_uitoa_base(w->g, 16)));
	if (p == SHA256)
		res = ft_stradd(res, ap_z(ft_uitoa_base(w->h, 16)));
	return (res);
}

void				block_op(unsigned int *w, t_words *word)
{
	int				j;
	unsigned int	t1;
	unsigned int	t2;

	j = 0;
	while (j < 64)
	{
		t1 = word->h + bsig1(word->e) + ch(word->e, word->f,
				word->g) + g_k[j] + w[j];
		t2 = bsig0(word->a) + maj(word->a, word->b, word->c);
		word->h = word->g;
		word->g = word->f;
		word->f = word->e;
		word->e = word->d + t1;
		word->d = word->c;
		word->c = word->b;
		word->b = word->a;
		word->a = t1 + t2;
		j++;
	}
}

char				*process_sha(unsigned int *m, unsigned long words, int p)
{
	int				i;
	int				j;
	unsigned int	*w;
	t_words			word;

	init(&word, p);
	i = 0;
	while (i < (int)words / 16)
	{
		w = malloc(sizeof(unsigned int) * 64);
		j = -1;
		while (++j < 16)
			w[j] = convert((char *)&m[i * 16 + j], 4);
		j--;
		while (++j < 64)
			w[j] = ssig1(w[j - 2]) + w[j - 7] + ssig0(w[j - 15]) + w[j - 16];
		reinit(&word);
		block_op(w, &word);
		i++;
		save(&word);
	}
	free(w);
	return (get_final_sha(&word, p));
}
