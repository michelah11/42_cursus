/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:34:52 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/18 17:49:43 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_node **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
