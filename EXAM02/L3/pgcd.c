#include <stdio.h>

int	ft_atoi(char *str)
{
	int	n;
    n = 0;
	while(*str >= 48 && *str <= 57)
	{
		n = (n * 10) +(*str - 48);
		str++;
	}
	return (n);
}

int main(int argc, char **argv)
{
    int div, pgcd, a, b;
    div = 1;
    pgcd = 0;
    if (argc == 3)
    {
        a = ft_atoi(argv[1]);
        b = ft_atoi(argv[2]);
        while ((div <= a) && (div <= b))
        {
            if (((a % div) == 0) && ((b % div) == 0))
                pgcd = div;
            div++;
        }
        printf("%d\n", pgcd);
        return (0);
    }
}