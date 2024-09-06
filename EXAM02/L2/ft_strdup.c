#include <stddef.h>
char *ft_strdup(char *src)
{
	char *dup;
	int i;
	int j;

	i = 0;
	while(src[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	while (src[j])
	{
		dup[j] = src[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}