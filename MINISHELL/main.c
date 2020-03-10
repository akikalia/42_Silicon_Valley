/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:46:07 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 17:48:16 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		str_alnum(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		search_dir(char *name, char *path)
{
	struct dirent	*file;
	DIR				*dir;

	dir = opendir(path);
	while ((file = readdir(dir)))
	{
		if (!ft_strcmp(file->d_name, name))
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

char	*search_dirs(char *name, char **arr)
{
	int				i;
	char			*temp;

	i = 0;
	while (arr[i])
	{
		if (search_dir(name, arr[i]))
		{
			temp = ft_sprintf("%s/%s", arr[i], name);
			free_arr(arr);
			return (temp);
		}
		i++;
	}
	free_arr(arr);
	return (NULL);
}

char	*get_path(t_map *mp, char *pr_name)
{
	char			*path;

	if (ft_strchr(pr_name, '/') || !(path = map_get(mp, "PATH")))
		return (ft_strdup(pr_name));
	else
		return (search_dirs(pr_name, ft_strsplit(path, ':')));
}

int		main(int argc, char **argv, char *envp[])
{
	char			*cmd;
	int				err;
	t_map			*mp;
	int				fd;

	arr_dup(&envp);
	mp = map_init();
	arrtomap(mp, envp);
	free_arr(envp);
	fd = (argc > 1) ? 1 : 0;
	if (fd)
		fd = open(argv[1], O_RDONLY);
	while (1)
	{
		err = 0;
		ft_printf("$> ");
		cmd = get_input(fd);
		parse(cmd, &argv, &err);
		if (!err)
			err = mng_exp(mp, &argv);
		argc = arr_size(argv);
		if (!err)
			action(argc, argv, mp);
		free_arr(argv);
	}
	if (fd) close(fd);
	map_free(mp);
	return (0);
}
