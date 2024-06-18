/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:31:26 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/17 22:42:43 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strjoin(const char *dest, const char *src)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) *(ft_strlen(dest) +ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
		str[i++] = dest[i++];
	while (src[j])
		str[i++] = src[j++];
	str[i] = '\0';
}
