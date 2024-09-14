/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:22:34 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/09 02:46:28 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	colored_line(t_fdf *fdf, t_point *point, int color1, int color2)
{
	t_color	*c;

	c = color_pallet_init(color1, color2);
	point->color = get_color(c, absolute(point->z),
			absolute(fdf->map->max_z));
	free(c);
}

static void	put_colors(t_fdf *fdf, t_point *point, int max, int min)
{
	if (fdf->cam->color_pallet == FALSE)
	{
		if (point->color == -1)
			point->color = LINE_DEFAULT;
	}
	else
	{
		if (point->z > 0.85 * max)
			colored_line(fdf, point, C_ORANGERED, C_RED);
		else if (point->z > 0.7 * max && point->z <= 0.85 * max)
			colored_line(fdf, point, C_ORANGE, C_ORANGERED);
		else if (point->z > 0.5 * max && point->z <= 0.7 * max)
			colored_line(fdf, point, C_GOLD, C_ORANGE);
		else if (point->z > 0.3 * max && point->z <= 0.5 * max)
			colored_line(fdf, point, C_YELLOW, C_GOLD);
		else if (point->z > 0.1 * max && point->z <= 0.3 * max)
			colored_line(fdf, point, C_LIME, C_YELLOW);
		else if (point->z >= 0 && point->z <= 0.1 * max)
			colored_line(fdf, point, C_GREEN, C_LIME);
		else if (point->z >= -0.1 * min && point->z < 0)
			colored_line(fdf, point, C_TEAL, C_GREEN);
		else if (point->z >= -0.3 * min && point->z <= -0.1 * min)
			colored_line(fdf, point, C_CYAN, C_TEAL);
		else if (point->z >= -0.5 * min && point->z <= -0.3 * min)
			colored_line(fdf, point, C_BLUE, C_CYAN);
		else if (point->z >= -0.7 * min && point->z <=  -0.5 * min)
			colored_line(fdf, point, C_INDIGO, C_BLUE);
		else if (point->z >= -0.85 * min && point->z <= -0.7 * min)
			colored_line(fdf, point, C_VIOLET, C_INDIGO);
		else
			colored_line(fdf, point, C_PINK, C_VIOLET);
	}
}

static void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	put_colors(fdf, &start, fdf->map->max_z, fdf->map->min_z);
	put_colors(fdf, &end, fdf->map->max_z, fdf->map->min_z);
	fdf->image->line = init_line(start, end, fdf);
	if (!fdf->image->line)
		close_all(fdf, 7);
	rotate(fdf->cam, fdf->image->line);
	project(fdf->cam, fdf->image->line);
	transform(fdf->cam, fdf->image->line);
	bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);
}

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf->image, MAX_PIXEL * 4);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	print_menu(fdf);
}
