/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:45:22 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/22 03:48:09 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_putuint_fd(unsigned int num, int fd)
{
	if (num > 9)
		ft_putuint_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

int	ft_putuint_pf(unsigned int num)
{
	int				len;
	unsigned int	temp;

	len = 0;
	temp = num;
	if (num == 0)
		len = 1;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	ft_putuint_fd(num, 1);
	return (len);
}
