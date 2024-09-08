#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    i = 1;
    j = 0;
    char c;
    if(argc > 1)
    {
        while(argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                c = argv[i][j];
                if (argv[i][j] >= 65 && argv[i][j] <= 90)
                    c = argv[i][j] + 32;
                else if ((argv[i][j] >= 97 && argv[i][j] <= 122) && (argv[i][j+1] == ' ' || argv[i][j+1] == '\t' || argv[i][j+1] == '\0'))
                    c = argv[i][j] - 32;
                write(1, &c, 1);
                j++;
            }
            i++;
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}
