/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:36:55 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 18:07:25 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_path(char *path, t_map *mp)
{
	char	cwd[200];

	getcwd(cwd, 200);
	if (!ft_strcmp(path, "-"))
		path = map_get(mp, "OLDPWD");
	if (!chdir(path))
	{
		map_add(mp, ft_strdup("OLDPWD"), ft_strdup(cwd));
		getcwd(cwd, 200);
		map_add(mp, ft_strdup("PWD"), ft_strdup(cwd));
	}
	else
		ft_printf("%s: No such file or directory.\n", path);
}

int		cd(int argc, char **argv, t_map *mp)
{
	if (argc == 1)
		change_path(map_get(mp, "HOME"), mp);
	else if (argc != 2)
		ft_printf("cd: Too many arguments.\n");
	else
		change_path(argv[1], mp);
	return (0);
}

int		setenv_ms(int argc, char **argv, t_map *mp)
{
	char	**arr;

	arr = maptoarr(mp);
	if (!argv[1])
		printstrarr(0, '\n', arr);
	else
	{
		if (argc > 3)
			ft_printf("setenv: Too many arguments.\n");
		else
		{
			if (!str_alnum(argv[1]))
			{
				ft_printf("setenv: Variable name must ");
				ft_printf("contain alphanumeric characters.\n");
			}
			else if (!argv[2])
				map_add(mp, ft_strdup(argv[1]), ft_strdup(""));
			else
				map_add(mp, ft_strdup(argv[1]), ft_strdup(argv[2]));
		}
	}
	free_arr(arr);
	return (0);
}

int		unsetenv_ms(char **argv, t_map *mp)
{
	int i;

	i = 0;
	if (!argv[1])
		ft_printf("unsetenv: Too few arguments.\n");
	else
	{
		while (argv[i])
			map_remove(mp, argv[i++]);
	}
	return (0);
}

int		builtin(int argc, char **argv, t_map *mp)
{
	char	**arr;

	if (!argc)
		return (1);
	else if (!ft_strcmp("cd", argv[0]))
		return (cd(argc, argv, mp));
	else if (!ft_strcmp("exit", argv[0]))
		exit(0);
	else if (!ft_strcmp("setenv", argv[0]))
		return (setenv_ms(argc, argv, mp));
	else if (!ft_strcmp("unsetenv", argv[0]))
		return (unsetenv_ms(argv, mp));
	else if (!ft_strcmp("env", argv[0]))
	{
		arr = maptoarr(mp);
		printstrarr(0, '\n', arr);
		free_arr(arr);
		return (0);
	}
	else if (!ft_strcmp("echo", argv[0]))
		return (printstrarr(1, ' ', argv));
	return (1);
}
