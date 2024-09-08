int	ft_atoi(char *str)
{
	int	n;
	int	sign;
	n = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while(*str >= 48 && *str <= 57)
	{
		n = (n * 10) + *str - 48;
		str++;
	}
	return (n * sign);
}