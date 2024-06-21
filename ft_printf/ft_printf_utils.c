#include "ft_printf.h"
#include "libft.h"

int	ft_putchar_pf(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
int	ft_putstr_pf(char *str)
{
	int	len;
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_pf(int num)
{
	char	*str;
	int	len;

	str = ft_itoa(num);
	len = ft_putstr_pf(str);
	return (len);
}
