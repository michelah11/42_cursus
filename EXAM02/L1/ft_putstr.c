#include <unistd.h>


void ft_putchar(int c)
{
	write (1, &c, 1);
}

void ft_putstr(char *c)
{
	while (*c)
	{
		ft_putchar(*c);
		c++;
	}
}