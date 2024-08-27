#include <stdio.h>
#include <stddef.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
			{
				k = i;
				break;
			}
			j++;
		}
		if (k)
			break;
		i++;
	}
	return (i);
}





int	main(void)
{
	printf("Code: %ld\n", ft_strcspn("trojan3", "1234" ));
	return (0);
}