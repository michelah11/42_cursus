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

void ft_putnumber(int x)
{
	if (x > 9)
	{
		ft_putnumber(x / 10);
		ft_putchar((x % 10) + '0');
	}
	else
		ft_putchar(x + '0');
}

int main(void)
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0)
			ft_putstr("fizz\n");
		else if (i % 5 == 0)
			ft_putstr("buzz\n");
		else if ((i % 3 == 0) && (i % 5 == 0))
			ft_putstr("fizzbuzz\n");
		else
		{
			ft_putnumber(i);
			ft_putchar('\n');

		}
		i++;
	}
	return (0);
}