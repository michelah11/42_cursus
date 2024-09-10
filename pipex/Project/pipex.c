/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:04:05 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/10 03:19:52 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *command, char **env)
{
	char	**cmd_parts;
	char	*cmd_path;

	cmd_parts = ft_split(command, ' ');
	cmd_path = find_command_path(cmd_parts[0], env);
	if (execve(cmd_path, cmd_parts, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_parts[0], 2);
		free_str(cmd_parts);
		exit(1);
	}
	free_str(cmd_parts);
	free(cmd_path);
}

void	child_process(char **argv, int *pipe_fd, char **env)
{
	int	fd;
	char *str;
	char *shell;
	char *error;

	fd = open_file(argv[1], 0);
	printf("%d\n", fd);
	if (fd < 0)
	{
		shell = ft_strchr(retrieve_env("SHELL", env), '/');
		str = ft_strdup(strerror(errno));
		str[0] += 32;
		error = ft_strjoin(shell + 1, ft_strjoin(str, ": "));
		printf("%s\n",error);
		ft_putendl_fd(argv[1], 2);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	execute_command(argv[2], env);
}

void	parent_process(char **argv, int *pipe_fd, char **env, int fd)
{
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	execute_command(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	process_id;
	int 	fd;

	if (argc != 5)
		handle_exit(1);
	fd = open_file(argv[4], 1);
	if (fd == -1)
		exit(1);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipex: pipe");
		exit(1);
	}
	process_id = fork();
	if (process_id == -1)
	{
		perror("pipex: fork");
		exit(1);
	}
	if (!process_id)
		child_process(argv, pipe_fd, env);
	waitpid(process_id, NULL, 0);
	parent_process(argv, pipe_fd, env, fd);
	close (fd);
	printf("hakunamatata");
	return (0);
}
