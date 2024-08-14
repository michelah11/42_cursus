/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:20 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/14 18:53:47 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int		count;
	bool	inwrd;

	while (*str)
	{
		inwrd = false;
		while (*str == c && *str)
			str++;
		while (*str != c && *str)
		{
			if (!inwrd)
			{
				count++;
				inwrd = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int		cursor;
	char			*word;
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		cursor++;
	while ((str[cursor + len] != c) && str[cursor + len])
		len++;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		word[i++] = str[cursor++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**lst;
	int		count;
	int		i;

	i = 0;
	count = count_words(str, c);
	if (!count)
		exit(1);
	lst = malloc(sizeof(char *) * (size_t)(count + 2));
	if (!lst)
		return (NULL);
	while (count-- >= 0)
	{
		if (i == 0)
		{
			lst[i] = malloc(sizeof(char));
			if (!lst[i])
				return (NULL);
			lst[i++][0] = '\0';
			continue ;
		}
		lst[i++] = get_next_word(str, c);
	}
	lst = NULL;
	return (lst);
}
