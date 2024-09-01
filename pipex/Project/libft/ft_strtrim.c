/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:45:15 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/13 23:43:35 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s;
	size_t	e;
	size_t	i;

	s = 0;
	while (in_set(set, s1[s]) && s1[s] != '\0')
		s++;
	e = ft_strlen(s1);
	while (in_set(set, s1[e - 1]) && e > s)
		e--;
	str = (char *)malloc(sizeof(*s1) * (e - s + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s < e)
		str[i++] = s1[s++];
	str[i] = 0;
	return (str);
}
