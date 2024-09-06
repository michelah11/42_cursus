#include <unistd.h>

int main(int argc, char **argv)
{
	char c;
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i + 1] >= 65 && argv[1][i + 1] <= 90)
			{
				c = argv[1][i];
				write(1, &c, 1);
				c = '_';
				write(1, &c, 1);
			}
			else if (*argv[1] >= 65 && *argv[1] <= 90)
			{
				c = argv[1][i] + 32;
				write(1, &c, 1);
			}
			else
			{
				c = argv[1][i];
				write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 2);
	return (0);
}
