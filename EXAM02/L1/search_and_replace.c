#include <unistd.h>

int	main(int argc, char **argv)
{
	char c;
	if (argc == 4 && !(argv[2][1]) && !(argv[3][1]))
	{
		while (*argv[1])
		{
			if (*argv[1] == *argv[2])
				c = *argv[3];
			else
				c = *argv[1];
			write(1, &c, 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}