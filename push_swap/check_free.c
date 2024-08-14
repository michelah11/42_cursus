/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:13:59 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/14 18:53:41 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (stack == NULL)
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

void	error_free(t_node **a, char **argv, bool argc_is_2)
{
	free_stack(a);
	if (argc_is_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == 43 || *str_nbr == 45
			|| (*str_nbr >= 48 && *str_nbr <= 57)))
		return (1);
	if ((*str_nbr == 43 || *str_nbr == 45)
		&& !(str_nbr[1] >= 48 && str_nbr[1] <= 57))
		return (1);
	while (*str_nbr++)
	{
		if (!(*str_nbr >= 48 && *str_nbr <= 57))
			return (1);
	}
	return (0);
}

int	error_repetition(t_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->number == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
