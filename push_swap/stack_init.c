/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:31 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/14 03:38:12 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_init(t_node **a, char **argv, bool argc_is_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_is_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_is_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, argc_is_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (argc_is_2)
		free_matrix(argv);
}
