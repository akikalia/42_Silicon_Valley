/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_rounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:11:05 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 06:11:13 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	round_one(t_words *w)
{
	w->func = &f;
	abcd(w, 0, 7, 1);
	dabc(w, 1, 12, 2);
	cdab(w, 2, 17, 3);
	bcda(w, 3, 22, 4);
	abcd(w, 4, 7, 5);
	dabc(w, 5, 12, 6);
	cdab(w, 6, 17, 7);
	bcda(w, 7, 22, 8);
	abcd(w, 8, 7, 9);
	dabc(w, 9, 12, 10);
	cdab(w, 10, 17, 11);
	bcda(w, 11, 22, 12);
	abcd(w, 12, 7, 13);
	dabc(w, 13, 12, 14);
	cdab(w, 14, 17, 15);
	bcda(w, 15, 22, 16);
}

void	round_two(t_words *w)
{
	w->func = &g;
	abcd(w, 1, 5, 17);
	dabc(w, 6, 9, 18);
	cdab(w, 11, 14, 19);
	bcda(w, 0, 20, 20);
	abcd(w, 5, 5, 21);
	dabc(w, 10, 9, 22);
	cdab(w, 15, 14, 23);
	bcda(w, 4, 20, 24);
	abcd(w, 9, 5, 25);
	dabc(w, 14, 9, 26);
	cdab(w, 3, 14, 27);
	bcda(w, 8, 20, 28);
	abcd(w, 13, 5, 29);
	dabc(w, 2, 9, 30);
	cdab(w, 7, 14, 31);
	bcda(w, 12, 20, 32);
}

void	round_three(t_words *w)
{
	w->func = &h;
	abcd(w, 5, 4, 33);
	dabc(w, 8, 11, 34);
	cdab(w, 11, 16, 35);
	bcda(w, 14, 23, 36);
	abcd(w, 1, 4, 37);
	dabc(w, 4, 11, 38);
	cdab(w, 7, 16, 39);
	bcda(w, 10, 23, 40);
	abcd(w, 13, 4, 41);
	dabc(w, 0, 11, 42);
	cdab(w, 3, 16, 43);
	bcda(w, 6, 23, 44);
	abcd(w, 9, 4, 45);
	dabc(w, 12, 11, 46);
	cdab(w, 15, 16, 47);
	bcda(w, 2, 23, 48);
}

void	round_four(t_words *w)
{
	w->func = &i;
	abcd(w, 0, 6, 49);
	dabc(w, 7, 10, 50);
	cdab(w, 14, 15, 51);
	bcda(w, 5, 21, 52);
	abcd(w, 12, 6, 53);
	dabc(w, 3, 10, 54);
	cdab(w, 10, 15, 55);
	bcda(w, 1, 21, 56);
	abcd(w, 8, 6, 57);
	dabc(w, 15, 10, 58);
	cdab(w, 6, 15, 59);
	bcda(w, 13, 21, 60);
	abcd(w, 4, 6, 61);
	dabc(w, 11, 10, 62);
	cdab(w, 2, 15, 63);
	bcda(w, 9, 21, 64);
}
