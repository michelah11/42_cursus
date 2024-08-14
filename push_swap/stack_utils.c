/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/14 04:23:27 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

t_node	*find_smallest(t_node *stack)
{
	long		smallest;
	t_node		*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->number < smallest)
		{
			smallest = stack->number;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_node	*return_cheapest(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
