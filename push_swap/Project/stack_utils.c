/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/19 03:55:15 by mabou-ha         ###   ########.fr       */
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
		stack = stack->next;
		count++;
	}
	return (count);
}

bool	stack_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->number > node->next->number)
			return (false);
		node = node->next;
	}
	return (true);
}

t_node	*find_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*find_min(t_node *node)
{
	long		min;
	t_node		*min_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->number < min)
		{
			min = node->number;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *node)
{
	long	max;
	t_node	*max_node;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->number > max)
		{
			max = node->number;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}
