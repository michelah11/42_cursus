/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:49:50 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/15 00:59:23 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst_ptr;

	lst_ptr = (t_list *)malloc(sizeof(t_list));
	if (!lst_ptr)
		return (NULL);
	lst_ptr->content = content;
	lst_ptr->next = NULL;
	return (lst_ptr);
}
