/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:04:05 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/19 03:17:14 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *command, char **env)
{
	char	**cmd_parts;
	char	*cmd_path;

	cmd_parts = ft_split(command, ' ');
	if (!cmd_parts || !cmd_parts[0])
		error(find_shell(env), "invalid command", env, cmd_parts);
	cmd_path = find_command_path(cmd_parts[0], env);
	if (!cmd_path)
		error(cmd_parts[0], "command not found", env, cmd_parts);
	if (execve(cmd_path, cmd_parts, env) == -1)
	{
		free(cmd_path);
		error(cmd_parts[0], strerror(errno), env, cmd_parts);
	}
	free_str(cmd_parts);
	free(cmd_path);
}

void	child_process(char **argv, int *pipe_fd, char **env)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(argv[1], strerror(errno), env, NULL);
	if (dup2(fd, STDIN_FILENO) == -1)
		error("dup2", strerror(errno), env, NULL);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error("dup2", strerror(errno), env, NULL);
	close(pipe_fd[0]);
	if (close(fd) == -1)
		error("close", strerror(errno), env, NULL);
	execute_command(argv[2], env);
}

void	parent_process(char **argv, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error(argv[4], strerror(errno), env, NULL);
	if (dup2(fd, STDOUT_FILENO) == -1)
		error("dup2", strerror(errno), env, NULL);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error("dup2", strerror(errno), env, NULL);
	close(pipe_fd[1]);
	if (close(fd) == -1)
		error("close", strerror(errno), env, NULL);
	execute_command(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	process_id;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error("pipe", strerror(errno), env, NULL);
		process_id = fork();
		if (process_id == -1)
			error("fork", strerror(errno), env, NULL);
		if (!process_id)
			child_process(argv, pipe_fd, env);
		waitpid(process_id, NULL, 0);
		parent_process(argv, pipe_fd, env);
	}
	else
	{
		ft_putendl_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>", 1);
		exit (0);
	}
	return (0);
}
