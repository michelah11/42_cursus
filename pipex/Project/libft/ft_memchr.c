/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:13:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/12 17:53:31 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	l;

	str = (unsigned char *)s;
	l = (unsigned char)c;
	while (n-- > 0)
	{
		if (*str == l)
			return ((void *)str);
		str++;
	}
	return (0);
}
