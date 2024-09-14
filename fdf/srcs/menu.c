/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:47:45 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/06 02:27:43 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (fdf->cam->projection == SIDE)
		projection = "Side view";
	else if (fdf->cam->projection == FRONT)
		projection = "Front view ";
	else if (fdf->cam->projection == TOP)
		projection = "Top view";
	return (projection);
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, projection);
	mlx_string_put(mlx, win, 30, y += 80, C_TEXT, "Press key for each command");
	mlx_string_put(mlx, win, 30, y += 80, C_TEXT, "Change Projection");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Top view 'O'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Front view 'L'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Side view 'K'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Perspective 'P'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Isometric 'I'");
	mlx_string_put(mlx, win, 30, y += 80, C_TEXT, "Zoom '-' | '+'");
	mlx_string_put(mlx, win, 30, y += 80, C_TEXT, "Rotate X 'S' | 'W'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Rotate Y 'Q' | 'E'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Rotate Z 'A' | 'D'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "Z scale 'Z' | 'X'");
	mlx_string_put(mlx, win, 30, y += 80, C_TEXT, "Reset 'R' | Colors 'SPACE'");
	mlx_string_put(mlx, win, 30, y += 80, C_TEXT, "'ESC' Close program");
}
