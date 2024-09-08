#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j, k,  dup;
    if (argc == 3)
    {
        i = 0;
        j = 0;
        while (argv[1][i])
        {
            dup = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    k = 0;
                    while (k < i)
                    {
                        if (argv[1][k] == argv[1][i])
                        {
                            dup = 1;
                            break;
                        }
                        k++;
                    }
                    if (dup == 0)
                    {
                        write(1, &argv[1][i], 1);
                        break;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}