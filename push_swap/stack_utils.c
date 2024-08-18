/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/18 16:48:03 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_node	*find_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_node	*find_min(t_node *stack)
{
	long		min;
	t_node		*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	long		max;
	t_node		*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MAX;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
