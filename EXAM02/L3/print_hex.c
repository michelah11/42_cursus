#include <unistd.h>

int ft_atoi(char *str)
{
    int res = 0;
    while (*str >= 48 && *str <= 57)
    {
        res = res * 10 +(*str - 48);
        str++;
    }
    return (res);
}

void ft_putnbr_base(int n, char *base)
{
    if (n > 15)
        ft_putnbr_base(n / 16, base);
    write(1, base + (n % 16), 1);
}

int main(int argc, char **argv)
{
    int n;
    if(argc == 2)
    {
        n = ft_atoi(argv[1]);
        ft_putnbr_base(n, "0123456789abcdef");
    }
    write(1, "\n", 1);
    return (0);
}