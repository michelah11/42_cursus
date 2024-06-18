/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:48:39 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/18 17:26:41 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *line_buffer)
{
	char	*left_sub;
	int		i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	left_sub = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i - 1);
	if (!left_sub)
	{
		return (NULL);
	}
	line_buffer[i + 1] = '\0';
	return (left_sub);
}

char	*fill_line_buffer(int fd, char *left_sub, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free (left_sub);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!left_sub)
			left_sub = ft_strdup("");
		temp = left_sub;
		left_sub = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (!left_sub)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_sub);
}

char	*get_next_line(int fd)
{
	static char	*left_sub;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (left_sub)
		{
			free(left_sub);
			left_sub = NULL;
		}
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_sub, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_sub = set_line(line);
	return (line);
}
