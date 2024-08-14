/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:33:26 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/14 21:10:27 by mabou-ha         ###   ########.fr       */
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
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

char	**ft_split(char *str, char c);
void	free_matrix(char **argv);
void	error_free(t_node **a, char **argv, bool argc_is_2);
void	free_stack(t_node **stack);
int		error_repetition(t_node *a, int nbr);
int		error_syntax(char *str_nbr);
void	stack_init(t_node **a, char **argv, bool argc_is_2);
void	init_nodes(t_node *a, t_node *b);
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);
void	append_node(t_node **stack, int nbr);
t_node	*find_last_node(t_node *head);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
bool	stack_sorted(t_node *stack);
int		stack_len(t_node *stack);
void	finish_rotation(t_node **stack, t_node *top_node, char stack_name);
void	tiny_sort(t_node **a);
void	handle_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);
void	sa(t_node **a, bool checker);
void	sb(t_node **b, bool checker);
void	ss(t_node **a, t_node **b, bool checker);
void	ra(t_node **a, bool checker);
void	rb(t_node **b, bool checker);
void	rr(t_node **a, t_node **b, bool checker);
void	rra(t_node **a, bool checker);
void	rrb(t_node **b, bool checker);
void	rrr(t_node **a, t_node **b, bool checker);
void	pa(t_node **a, t_node **b, bool checker);
void	pb(t_node **b, t_node **a, bool checker);

#endif
