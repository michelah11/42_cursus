#include <unistd.h>

int	main(int argc, char **argv)
{
	char c;
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (*argv[1] >= 65 && *argv[1] <= 90)
				c = *argv[1] + 32;
			else if (*argv[1] >= 97 && *argv[1] <= 122)
				c = *argv[1] - 32;
			else
				c = *argv[1];
			write(1, &c, 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}