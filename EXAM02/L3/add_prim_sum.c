#include <unistd.h>

int ft_atoi(char *s)
{
    int neg = 1;
    int res = 0;
    while (*s == 32 || (*s >=9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            neg = -1;
    }
    while (*s >= 48 && *s <= 57)
    {
        res = res * 10 + (*s - 48);
        s++;
    }
    return (res * neg);
}

int ft_isprime(int n)
{
    int i;

    i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = n % 10 + 48;
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n, sum;
    
    if(argc == 2)
    {
        sum = 0;
        n = ft_atoi(argv[1]);
        while (n)
        {
            if (ft_isprime(n))
                sum += n;
            n--;
        }
        ft_putnbr(sum);
        return (0);
    }
}