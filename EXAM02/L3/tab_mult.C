#include <unistd.h>

int ft_atoi(char *str)
{
    int res;
    res = 0;
    while(*str >= 48 && *str <= 57)
    {
        res = res *10 + (*str - 48);
        str++;
    }
    return (res);
}

void ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + 48;
    write(1, &c, 1);
}
int main(int argc, char **argv)
{
    int n;
    int i = 1;
    if (argc == 2)
    {
        n = ft_atoi(argv[1]);
        while (i < 10)
        {
            ft_putnbr(i);
            write(1," x ", 3);
            ft_putnbr(n);
            write(1, " = ", 3);
            ft_putnbr(i * n);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}