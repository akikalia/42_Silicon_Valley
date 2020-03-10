/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:21:39 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/23 00:46:02 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char				*sha256(char *str)
{
	unsigned int		words;
	char				*temp;

	words = appendsha(&str) / 4;
	temp = (process_sha((unsigned int *)str, words, SHA256));
	free(str);
	return (temp);
}

char				*sha224(char *str)
{
	unsigned int		words;
	char				*temp;

	words = appendsha(&str) / 4;
	temp = (process_sha((unsigned int *)str, words, SHA224));
	free(str);
	return (temp);
}

char				*md5(char *str)
{
	unsigned long		words;
	char				*temp;

	words = append(&str, MD5) / 4;
	temp = (process_md5((unsigned int *)str, words));
	free(str);
	return (temp);
}
