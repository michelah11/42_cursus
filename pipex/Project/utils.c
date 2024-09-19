/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:04:37 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/19 03:15:05 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_shell(char **env)
{
	int		i;
	char	*shell_name;
	char	*shell_path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHELL=", 6) == 0)
		{
			shell_path = env[i] + 6;
			shell_name = ft_strrchr(shell_path, '/');
			if (shell_name)
				return (shell_name + 1);
			return (env[i] + 6);
		}
		i++;
	}
	return ("bash");
}

char	*error(char *cmd, char *msg, char **env, char **parts)
{
	char	*shell;

	shell = find_shell(env);
	ft_putstr_fd(shell, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	if (parts)
		free_str(parts);
	fflush(stderr);
	exit(128);
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

char	*find_command_path(char *command, char **env)
{
	int		i;
	char	*part_path;
	char	*path;
	char	**paths;

	i = 0;
	while (env[i] && strncmp(env[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_str(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_str(paths);
	return (NULL);
}
