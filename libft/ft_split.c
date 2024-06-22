/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:07:16 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/13 23:46:33 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_until_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	nb;

	if (*s == '\0')
		return (0);
	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			nb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (nb);
}

void	copy_until_c(char *dest, const char **src, char c)
{
	while (**src != c && **src != '\0')
		*dest++ = *(*src)++;
	*dest = '\0';
}

void	free_all(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(str[i++]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int			word_nb;
	int			i;
	char		**str;
	const char	*dup;

	word_nb = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (word_nb + 1));
	if (!str)
		return (NULL);
	dup = s;
	i = 0;
	while (word_nb--)
	{
		while (*dup == c)
			dup++;
		str[i] = (char *)malloc(sizeof(char) * (count_until_c(dup, c) + 1));
		if (!str[i])
		{
			free_all(str, i);
			return (NULL);
		}
		copy_until_c(str[i++], &dup, c);
	}
	str[i] = NULL;
	return (str);
}
