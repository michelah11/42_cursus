/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:43:46 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/22 04:02:54 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_formatter(const char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_pf(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr_pf(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_putptr_pf(va_arg(ap, size_t));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_pf(va_arg(ap, int));
	else if (c == 'u')
		len += ft_putuint_pf(va_arg(ap, unsigned int));
	else if (c == 'x')
		len += ft_puthex_pf(va_arg(ap, unsigned int), LOWER_CASE_HEX);
	else if (c == 'X')
		len += ft_puthex_pf(va_arg(ap, unsigned int), UPPER_CASE_HEX);
	else if (c == '%')
		len += ft_putchar_pf('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formatter(str[i + 1], ap);
			i++;
		}
		else
			len += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
