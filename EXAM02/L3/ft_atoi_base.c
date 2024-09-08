#include <unistd.h>
#include <stdio.h>

int is_clear(char *base)
{
    int i, j;

    i = 0;
    while(base[i])
    {
        j = i + 1;
        if (base[i] < 48 || (base[i] > 57 && base[i] < 65) || (base[i] > 90 && base[i] < 97) || base[i] > 122)
            return (0);
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int in_str(char *base, char c)
{
    int i;

    i = 0;
    while (base[i])
    {
        if ((base[i] == c) || (base[i] - 32 == c))
            return (1);
        i++;
    }
    return (0);
}

int ft_atoi_base(char *str, char *base)
{
    int sign;
    int res;
    int n;
    
    n = is_clear(base);
    if (n == 0)
        return (0);
    sign = 1;
    res = 0;
    while(*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while(*str && in_str(base, *str))
    {
        if (*str >= 65 && *str <= 97)
            res = res * n + (*str - 55);
        else if (*str >= 97 && *str <= 122)
            res = res * n + (*str - 87);
        else if (*str >= 48 && *str <= 57)
            res = res * n + (*str - 48);
        str++;
    }
    return (res *sign);
}


int main(void)
{
    char *str1 = "10111000101010";
    char *str2 = "21647";
    char *str3 = "974564";
    char *str4 = "adf45a4";
    char *str5 = "AB45CE";
    char *base_oct = "01234567";
    char *base_hex = "0123456789abcdef";  // Base 16
    char *base_bin = "01";                // Base 2
    char *base_dec = "0123456789";        // Base 10

    int result1 = ft_atoi_base(str2, base_oct);
    int result2 = ft_atoi_base(str4, base_hex);
    int result3 = ft_atoi_base(str1, base_bin);
    int result4 = ft_atoi_base(str3, base_dec);
    int result5 = ft_atoi_base(str2, base_dec);
    int result6 = ft_atoi_base(str5, base_hex);

    printf("String '%s' in base %s: %d\n", str2, base_oct, result1);
    printf("String '%s' in base %s: %d\n", str4, base_hex, result2);
    printf("String '%s' in base %s: %d\n", str1, base_bin, result3);
    printf("String '%s' in base %s: %d\n", str3, base_dec, result4);
    printf("String '%s' in base %s: %d\n", str2, base_dec, result5);
    printf("String '%s' in base %s: %d\n", str5, base_hex, result6);


    return 0;
}