/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_a_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:33:10 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/18 17:47:46 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_a_target_node(t_node *a, t_node *b)
{
	t_node		*current_b;
	t_node		*target_node;
	long		best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_b = b;
		while (current_b)
		{
			if (current_b->number > a->number
				&& current_b->number < best_match_index)
			{
				best_match_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (LONG_MAX == best_match_index)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long		best_match_value;
	t_node		*best_match_node;

	if (!stack)
		return ;
	best_match_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < best_match_value)
		{
			best_match_value = stack->push_price;
			best_match_node = stack;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = true;
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		a->push_price = a->current_position;
		if ((!(a->above_median)))
			a->push_price = len_a - (a->current_position);
		if (a->target->above_median)
			a->push_price += a->target->current_position;
		else
			a->push_price += len_b - (a->target->current_position);
		a = a->next;
	}
}

void	node_a_init(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_a_target_node(a, b);
	set_price(a, b);
	set_cheapest(a);
}
