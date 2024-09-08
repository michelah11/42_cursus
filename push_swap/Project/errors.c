/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:13:59 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/08 23:28:03 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *arg)
{
	if (!(*arg == '+' || *arg == '-'
			|| (*arg >= '0' && *arg <= '9')))
		return (1);
	if ((*arg == '+' || *arg == '-')
		&& !(arg[1] >= '0' && arg[1] <= '9'))
		return (1);
	while (*++arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->number == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_node **a, char **argv)
{
	free_stack(a);
	free_args(argv - 1);
	write(2, "Error\n", 6);
	exit(1);
}
