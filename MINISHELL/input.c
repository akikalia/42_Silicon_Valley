/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:27:58 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 17:34:47 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(int fd)
{
	char	buf[1];
	char	temp[BUFF_SIZE + 1];
	char	*res;
	int		i;

	res = "";
	i = 0;
	while ((read(fd, buf, 1) > 0) && buf[0] != '\n')
	{
		if (i < BUFF_SIZE)
			temp[i] = buf[0];
		i++;
		temp[i] = '\0';
	}
	res = ft_strdup(temp);
	if (fd)
		ft_printf("%s\n", res);
	return (res);
}

void	parse(char *cmd, char ***argv, int *err)
{
	int		i;
	char	m;

	m = 0;
	i = 0;
	while (cmd[i])
	{
		if (ft_isspace(cmd[i]) && cmd[i] != ' ')
			cmd[i] = ' ';
		if (cmd[i] == '\"')
			m = (m == 0) ? m + 1 : m - 1;
		else if (cmd[i] == ' ' && m == 0)
			cmd[i] = 1;
		i++;
	}
	i = -1;
	while (cmd[++i])
		if (cmd[i] == '\"')
			cmd[i] = 1;
	*argv = ft_strsplit(cmd, 1);
	free(cmd);
	if (m != 0)
		*err = ft_printf("minishell: no end quoute\n");
}

void	action(int argc, char **argv, t_map *mp)
{
	int		pid;
	char	**arr;
	char	*path;

	if (builtin(argc, argv, mp))
	{
		if (!(pid = fork()))
		{
			arr = maptoarr(mp);
			if ((path = get_path(mp, argv[0])))
			{
				if (execve(path, argv, arr) == -1)
					ft_printf("zsh: no such file or directory: %s\n", path);
			}
			else
				ft_printf("zsh: command not found: %s\n", argv[0]);
			free(arr);
			free(path);
			exit(0);
		}
		wait(NULL);
	}
}

int		mng_exp(t_map *mp, char ***argv)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*argv)[i])
	{
		if ((*argv)[i][0] == '~')
		{
			temp = (*argv)[i];
			(*argv)[i] = ft_strjoin(map_get(mp, "HOME"), temp + 1);
			free(temp);
		}
		else if ((*argv)[i][0] == '$')
		{
			temp = map_get(mp, (*argv)[i] + 1);
			if (temp == NULL)
				return (ft_printf("%s: Undefined variable.\n", (*argv)[i]));
			free((*argv)[i]);
			(*argv)[i] = ft_strdup(temp);
		}
		i++;
	}
	return (0);
}
