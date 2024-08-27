int	ft_strcmp(char *s1, char *s2)
{
	char *str1;
	char *str2;
	str1 = s1;
	str2 = s2;
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}