/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:52:24 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 18:06:43 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
# include "libft/libft.h"
# define BUFF_SIZE 32

int		mng_exp(t_map *mp, char ***argv);
void	action(int argc, char **argv, t_map *mp);
void	parse(char *cmd, char ***argv, int *err);
char	*get_input(int fd);
int		builtin(int argc, char **argv, t_map *mp);
int		unsetenv_ms(char **argv, t_map *mp);
int		setenv_ms(int argc, char **argv, t_map *mp);
int		cd(int argc, char **argv, t_map *mp);
void	change_path(char *path, t_map *mp);
int		arr_size(char **arr);
int		printstrarr(char arr_start, char spacec, char **argv);
void	free_arr(char **arr);
void	arr_dup(char ***arr);
char	*get_path(t_map *mp, char *pr_name);
int		str_alnum(char *str);

#endif
