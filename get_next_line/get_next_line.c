/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:13:26 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/07/19 00:42:33 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *line)
{
	char	*remainder;
	int		nl_pos;

	nl_pos = 0;
	while (line[nl_pos] != '\n' && line[nl_pos] != '\0')
		nl_pos++;
	if (line[nl_pos] == '\0')
		return (NULL);
	else
	{
		remainder = ft_substr(line, nl_pos + 1, ft_strlen(line) - nl_pos - 1);
		if (!remainder)
			return (NULL);
		line[nl_pos + 1] = '\0';
	}
	return (remainder);
}

char	*read_from_fd(int fd, char *buffer, ssize_t *bytes)
{
	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes == -1)
		return (NULL);
	buffer[*bytes] = '\0';
	return (buffer);
}

char	*process_buffer(char *content, char *buffer)
{
	char	*old;

	if (!content)
		content = ft_strdup("");
	old = content;
	content = ft_strjoin(old, buffer);
	free(old);
	return (content);
}

char	*fill_line_buffer(int fd, char *content, char *buffer)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		if (!read_from_fd(fd, buffer, &bytes))
		{
			free (content);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		content = process_buffer(content, buffer);
		if (!content)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(remainder), remainder = NULL, NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, remainder, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = set_line(line);
	if (line && line[0] == '\0' && !remainder)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
