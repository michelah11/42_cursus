/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:40:53 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/24 02:11:15 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sanitized_base(char *base)
{
	char	*str;
	int		n;
	int		i;
	int		j;

	n = 0;
	i = 0;
	j = 0;
	str = base;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == 43 || base[i] == 45 || base[i] == 32)
			return (0);
		while (str[j] != '\0')
		{
			if (str[j] == base[i])
				return (0);
			j++;
		}
		n++;
		i++;
	}
	return (n);
}

int	find_index(char c, char *str)
{
	int	index;

	index = 0;
	while (*str)
	{
		if (c == *str)
			return (index);
		str++;
		index++;
	}
	return (-1);
}

int	has_char(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	number;
	int	n;

	n = sanitized_base(base);
	if (n < 2)
		return (0);
	sign = 1;
	number = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && has_char(*str, base))
	{
		number = number * n + find_index(*str, base);
		str++;
	}
	return (sign * number);
}
