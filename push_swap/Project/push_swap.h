/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:33:26 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/08 23:22:58 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_node
{
	int				number;
	int				current_position;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		error_syntax(char *arg);
int		error_duplicate(t_node *a, int nbr);
void	free_stack(t_node **stack);
void	free_errors(t_node **a, char **argv);
void	set_current_position(t_node *stack);
void	set_cheapest(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	node_a_init(t_node *a, t_node *b);
void	node_b_init(t_node *a, t_node *b);
void	append_node(t_node **stack, int nbr);
void	stack_init(t_node **a, char **argv);
t_node	*get_cheapest(t_node *stack);
void	finish_rotation(t_node **stack, t_node *top_node, char stack_name);
int		stack_len(t_node *stack);
bool	stack_sorted(t_node *stack);
t_node	*find_last_node(t_node *head);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
char	**ft_split(char *str, char c);
void	turk_sort(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b, bool checker);
void	pb(t_node **b, t_node **a, bool checker);
void	ra(t_node **a, bool checker);
void	rb(t_node **b, bool checker);
void	rr(t_node **a, t_node **b, bool checker);
void	sa(t_node **a, bool checker);
void	sb(t_node **b, bool checker);
void	ss(t_node **a, t_node **b, bool checker);
void	rra(t_node **a, bool checker);
void	rrb(t_node **b, bool checker);
void	rrr(t_node **a, t_node **b, bool checker);
void	tiny_sort(t_node **a);
void	free_args(char **argv);

#endif
