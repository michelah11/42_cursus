/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:52:16 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/18 04:05:38 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	if (!str)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char	const *c, unsigned int start, size_t len)
{
	char	*s;
	int		i;

	if (!c)
		return (NULL);
	if (len > ft_strlen(c + start))
		len = ft_strlen(c + start);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		s[i] = c[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(const char *dest, const char *src)
{
	int		i;
	int		j;
	char	*str;

	if (!dest || !src)
		return (NULL);
	str = (char *)malloc(sizeof(char) *(ft_strlen(dest) + ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
	{
		str[i] = dest[i];
		i++;
	}
	while (src[j])
		str[i++] = src[j++];
	str[i] = '\0';
	return (str);
}
