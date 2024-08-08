/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:33:26 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/08 20:03:56 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

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

#endif
