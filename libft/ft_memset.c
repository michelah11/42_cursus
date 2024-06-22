/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:10:52 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/10 19:40:01 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*s_ptr;

	s_ptr = s;
	while (n--)
	{
		*(unsigned char *)s_ptr = (unsigned char)c;
		s_ptr++;
	}
	return (s);
}
