#include <unistd.h>


int  ft_strlen(char *str)
{
    int i;
    i = 0;
    while (*str != '\0')
    {
        i++;
        str++;
    }
    return (i);
}
int main(int argc, char **argv)
{
    int i, j;
    i = 0;
    j = 0;
    int n = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    n++;
                    break;
                }
                j++;
            }
            i++;
        }
        if (n == ft_strlen(argv[1]))
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}