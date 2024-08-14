/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:31 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/14 21:45:55 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	int		neg;
	long	num;

	num = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * neg);
}

void	stack_init(t_node **a, char **argv, bool argc_is_2)
{
	long	nbr;
	int		i;

	i = 1;
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
