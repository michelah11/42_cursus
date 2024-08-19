/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:20 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/19 04:01:47 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int		cursor = 0;
	char			*next_word;
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char **ft_split(char *str, char c) {
    char **dest;
    int word_count;
    int i;

    i = 0;
    word_count = count_words(str, c);
    if (!word_count)
        exit(1); // Consider handling this error more gracefully
    dest = malloc(sizeof(char *) * (size_t)(word_count + 1)); // Allocate for all words + NULL
    if (!dest)
        return (NULL);
    while (word_count-- > 0) {
        dest[i++] = get_next_word(str, c);
    }
    dest[i] = NULL;
    return (dest);
}

void	free_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}
