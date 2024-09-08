#include <stdio.h>
#include <stddef.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	size_t j;
	size_t k;

	k = 0;
	while (*s1)
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == *s1)
			{
				k = j;
				break ;
			}
			j++;
		}
		if (k)
			break ;
		s1++;
	}
	return (s1);
}





int	main(void)
{
	printf("Code: %ld\n", ft_strcspn("trojan3", "1234" ));
	return (0);
}