/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:45:03 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/08 14:35:01 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_denied(const char *str)
{
	if (strrchr(str, '/') != NULL)
		ft_printf("ft_ls: %s: Permission denied\n", ft_strrchr(str, '/') + 1);
	else
		ft_printf("ft_ls: %s: Permission denied\n", str);
}

void	print_not_dir(const char *str)
{
	if (strrchr(str, '/') != NULL)
		ft_printf("ft_ls: %s: Not a directory\n", ft_strrchr(str, '/') + 1);
	else
		ft_printf("ft_ls: %s: Not a directory\n", str);
}

void	print_usage(char c)
{
	ft_printf(
		"ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] [file ...]\n", c);
	exit(1);
}
