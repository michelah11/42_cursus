/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:20:07 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/17 22:30:26 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *c, unsigned int start, size_t size)
{
	char	*s;
	int	i;

	if (!c)
		return (NULL);
	if (size > ft_strlen(s + start))
		size = ft_strlen(s + start);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = c[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
