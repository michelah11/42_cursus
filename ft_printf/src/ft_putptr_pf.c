/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:45:06 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/22 04:28:53 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_puthex_ulong(unsigned long num, char *base)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex_ulong(num / 16, base);
	len += ft_putchar_pf(base[num % 16]);
	return (len);
}

int	ft_putptr_pf(size_t num)
{
	int				value;

	value = 0;
	if (!num)
	{
		value += ft_putstr_pf(NULL_POINTER);
		return (value);
	}
	value = ft_putstr_pf("0x");
	value += ft_puthex_ulong(num, LOWER_CASE_HEX);
	return (value);
}
