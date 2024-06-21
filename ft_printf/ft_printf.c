#include "ft_printf.h"
#include "libft.h"

int	ft_formatter(const char c, va_list ap)
{
	int	len;
	if (c == 'c')
		len += ft_putchar_pf(va_arg(ap, char));
	else if (c == 's')
		len += ft_putstr_pf(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_putptr_pf(va_arg(ap, char));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_pf(va_arg(ap, float));
	else if (c == 'u')
		len += ft_putuint_pf(va_arg(ap, char));
	else if (c == 'x')
		len += ft_puthex_pf(va_arg(ap, char), LOWER_CASE_HEX);
	else if (c == 'X')
		len += ft_puthex_pf(va_arg(ap, char), UPPER_CASE_HEX);
	else if (c == '%')
		len += ft_putchar_pf('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		int	ft_formatter(char c, va_list ap);
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
