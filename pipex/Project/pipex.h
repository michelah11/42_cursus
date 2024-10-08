/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:03:50 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/19 03:14:41 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"

char	*find_shell(char **env);
char	*error(char *cmd, char *msg, char **env, char **parts);
void	free_str(char **str);
char	*find_command_path(char *command, char **env);
void	execute_command(char *command, char **env);
void	child_process(char **av, int *pipe_fd, char **env);
void	parent_process(char **argv, int *pipe_fd, char **env);
char	*find_shell(char **env);

#endif
