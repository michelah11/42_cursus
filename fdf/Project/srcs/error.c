/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:01:13 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/08/24 02:13:12 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_putstr_fd("FDF closed.\n", 1);
	else if (exit_code == 1)
		ft_putstr_fd("Error. Usage: ./fdf <file path\n>", 1);
	else if (exit_code == 2)
		ft_putstr_fd("Cannot read file.\n", 1);
	else if (exit_code == 3)
		ft_putstr_fd("Cannot Initialize fdf.\n", 1);
	else if (exit_code == 4)
		ft_putstr_fd("Cannot parse map.\n", 1);
	else if (exit_code == 5)
		ft_putstr_fd("Cannot create image.\n", 1);
	else if (exit_code == 6)
		ft_putstr_fd("Cannot initialize camera.\n", 1);
	else if (exit_code == 7)
		ft_putstr_fd("FDF closed.", 1);
	else if (exit_code == 8)
		ft_putstr_fd("Unable to initialize color.\n", 1);
}
