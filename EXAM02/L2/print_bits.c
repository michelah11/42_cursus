#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i;
    unsigned char m, bit;
    i = 7;
    m = 1;
    while (i >= 0)
    {
        bit = ((octet >> i) & m) + 48;
        write(1, &bit, 1);
        i--;
    }
}

int main(void)
{
    print_bits(16);
    return (0);
}