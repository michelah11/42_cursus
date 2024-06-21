#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOWER_CASE_HEX "0123456789abcdef"
# define UPPER_CASE_HEX "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_formatter(char c, va_list ap);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putptr_pf(void *ptr);
int	ft_putnbr_pf(int num);
int	ft_putuint_pf(unsigned int num);
int	ft_puthex_pf(unsigned int num, char *base);

#endif
