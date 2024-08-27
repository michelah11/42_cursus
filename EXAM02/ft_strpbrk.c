#include <stdio.h>
#include <stddef.h>

char *ft_strpbrk(const char *s, const char *reject)
{
	size_t j;
	size_t k;

	k = 0;
	while (*s)
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == *s)
			{
				k = j;
				break ;
			}
			j++;
		}
		if (k)
			break ;
		s++;
	}
	return (s);
}





int	main(void)
{
	printf("Code: %ld\n", ft_strcspn("trojan3", "1234" ));
	return (0);
}