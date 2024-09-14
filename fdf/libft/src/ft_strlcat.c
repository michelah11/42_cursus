/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:27:43 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/21 17:42:35 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	r;

	i = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	r = ft_strlcpy(dst, src, size - i);
	return (i + r);
}
