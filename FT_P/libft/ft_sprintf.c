/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:51:23 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/09 15:51:40 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_sprintf(const char *format, ...)
{
	va_list		argptr;
	t_str		n;
	int			i;
	char		*strcpy;
	int			m;

	m = 0;
	n.num = NULL;
	n.mid = NULL;
	n.temp = NULL;
	i = 0;
	n.mid = ft_strdup(format);
	strcpy = n.mid;
	va_start(argptr, format);
	n.temp = n.mid;
	make_str(&n, i, &m, &argptr);
	n.num = ft_stradd(n.num, ft_strdup(n.temp));
	va_end(argptr);
	free(strcpy);
	return (n.num);
}
