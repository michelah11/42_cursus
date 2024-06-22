/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:46:10 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/22 03:35:41 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_lenhex(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_puthex_fd(unsigned int num, char *base, int fd)
{
	if (num >= 16)
		ft_puthex_fd(num / 16, base, fd);
	ft_putchar_fd(base[num % 16], fd);
}

int	ft_puthex_pf(unsigned int num, char *base)
{
	ft_puthex_fd(num, base, 1);
	return (ft_lenhex(num));
}
