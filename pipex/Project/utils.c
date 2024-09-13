/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:04:37 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/11 06:02:12 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int exit_code)
{
	if (exit_code == 1)
		ft_putstr_fd("Pipex: Pipe failed\n", 2);
	else if (exit_code == 2)
		ft_putstr_fd("Pipex: Fork failed\n", 2);
	else if (exit_code == 3)
		ft_putstr_fd("Pipex: Command execution failed\n", 2);
	else if (exit_code == 4)
		ft_putstr_fd("Pipex: File could not be opened\n", 2);
	else if (exit_code == 5)
		ft_putstr_fd("Pipex: Command path not found\n", 2);
	else if (exit_code == 6)
		ft_putstr_fd("Pipex: Command not found\n", 2);
	else if (exit_code == 7)
		ft_putstr_fd("Pipex: Execve failed\n", 2);
	exit(0);
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
	while(ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	free_str(paths);
	return (0);
}
