/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:55:36 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/09 20:48:45 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}

static int	handle_exit(t_fdf *fdf)
{
	close_all(fdf, 0);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error_by_code(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_expose_hook(fdf->win, &key_press_handle, fdf);
	mlx_hook(fdf->win, X_ICON_WIN, 0, handle_exit, fdf);
	mlx_loop(fdf->mlx);
}
