#include <unistd.h>

void	print_alphachar(int c)
{
	int i;
	if (c >= 97)
		i = c - 96;
	else if (c >= 65)
		i = c - 64;
	while (i--)
		write(1, &c, 1);
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if ((*argv[1] >= 65 && * argv[1] <= 90) || (*argv[1] >= 97 && * argv[1] <= 122))
				print_alphachar(*argv[1]);
			else
				write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 2);
	return (0);
}