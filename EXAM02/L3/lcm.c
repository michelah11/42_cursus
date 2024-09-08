#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int i;
    if (a > b)
        i = a;
    else
        i = b;
    while (i)
    {
        if ((i % a == 0) && (i % b == 0))
            return (i);
        i++;
    }
    return (0);
}

int	main(void)
{
	printf("%u\n", lcm(14, 24));
}