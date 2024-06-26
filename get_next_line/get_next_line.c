/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:13:26 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/26 22:18:11 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *ln_bf)
{
	char	*left_sub;
	int		i;

	i = 0;
	while (ln_bf[i] != '\n' && ln_bf[i] != '\0')
		i++;
	if (ln_bf[i] == '\0')
		return (NULL);
	else
	{
		left_sub = ft_substr(ln_bf, i + 1, ft_strlen(ln_bf) - i - 1);
		if (!left_sub)
			return (NULL);
		ln_bf[i + 1] = '\0';
	}
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
		else if (b_read == 0 && (!left_sub || left_sub[0] == '\0'))
		{
			free (left_sub);
			left_sub = NULL;
			break ;
		}
		buffer[b_read] = '\0';
		if (!left_sub)
			left_sub = ft_strdup("");
		temp = left_sub;
		left_sub = ft_strjoin(temp, buffer);
		free (temp);
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
	if (line && line[0] == '\0' && !left_sub)
		return (ft_strdup(""));
	return (line);
}
