char *ft_strcpy(char *s1, char *s2)
{
	char *str1;
	char *str2;

	str1 = s1;
	str2 = s2;

	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (s1);
}