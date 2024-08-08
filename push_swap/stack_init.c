/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:31 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/08 23:02:13 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_atol(char *str)
{
	int		neg;
	long	num;
	char	*s;

	s = str;
	neg = 1;
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		s++;
		neg *= -1;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num * neg);
}

void	stack_init(t_node **a, char **argv, bool 2_argc)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if ()
	}
}
