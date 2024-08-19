/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:32:47 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/19 11:03:06 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	move_nodes(t_node **a, t_node **b, bool side)
{
	t_node	*cheapest_node;

	if (side == false)
	{
		cheapest_node = get_cheapest(*a);
		if (cheapest_node->above_median && cheapest_node->target->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target->above_median))
			reverse_rotate_both(a, b, cheapest_node);
		finish_rotation(a, cheapest_node, 'a');
		finish_rotation(b, cheapest_node->target, 'b');
		pb(b, a, false);
	}
	else
	{
		finish_rotation(a, (*b)->target, 'a');
		pa(a, b, false);
	}
}

static void	min_on_top(t_node **a)
{
	while ((*a)->number != find_min(*a)->number)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	turk_sort(t_node **a, t_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		node_a_init(*a, *b);
		move_nodes(a, b, false);
	}
	tiny_sort(a);
	while (*b)
	{
		node_b_init(*a, *b);
		move_nodes(a, b, true);
	}
	set_current_position(*a);
	min_on_top(a);
}
