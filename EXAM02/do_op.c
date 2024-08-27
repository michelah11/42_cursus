#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n1;
	int n2;
	char op;
	if (argc == 4 && !argv[2][1])
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[3]);
		op = argv[2][0];
		if (op == 43)
			printf("%d", n1 + n2);
		else if (op == 45)
			printf("%d", n1 - n2);
		else if (op == 47)
			if (n2 != 0)
				printf("%d", n1 / n2);
		else if (op == 42)
			printf("%d", n1 * n2);
		else if (op == 37)
			if (n2 != 0)
				printf("%d", n1 % n2);
	}
	printf("\n");
	return (0);
}