/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:04:37 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/01 05:10:57 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_exit(int exit_code)
{
	if (exit_code == 1)
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(0);
}

int	open_file(char *filename, int in_out_mode)
{
	int	fd;

	if (in_out_mode == 0)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit(0);
	return (fd);
}

void	free_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*retrieve_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		while (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*find_command_path(char *command, char **env)
{
	int		i;
	char	*cmd_path;
	char	**path_dirs;
	char	*exec_path;
	char	**s_cmd;

	path_dirs = ft_split(retrieve_env("PATH", env), ':');
	s_cmd = ft_split(command, ' ');
	i = 0;
	while (path_dirs[i])
	{
		cmd_path = ft_strjoin(path_dirs[i], "/");
		exec_path = ft_strjoin(cmd_path, s_cmd[0]);
		free(cmd_path);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			free_str(path_dirs);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	free_str(path_dirs);
	free_str(s_cmd);
	return (NULL);
}
