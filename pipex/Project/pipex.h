/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:03:50 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/11 05:58:23 by mabou-ha         ###   ########.fr       */
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

void	error(int exit_code);
int		open_file(char *filename, int in_out_mode);
void	free_str(char **str);
char	*find_command_path(char *command, char **env);
void	execute_command(char *command, char **env);
void	child_process(char **av, int *pipe_fd, char **env);
void	parent_process(char **argv, int *pipe_fd, char **env);

#endif
