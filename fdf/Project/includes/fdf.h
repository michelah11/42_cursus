/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:43:50 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/09 20:48:29 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "keys.h"
# include "colors.h"

# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		1200
# define WINDOW_HEIGHT		900
# define MAX_PIXEL			1080000

# define LINE_DEFAULT		C_WHITE
# define BACKGROUND_DEFAULT	C_GREY
# define C_TEXT				C_WHITE

# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_D_1				0.01745329
# define ANG_D_30				0.52359877
# define ANG_D_45				0.78539816

enum e_projection
{
	ISOMETRIC,
	FRONT,
	SIDE,
	PERSPECTIVE,
	TOP
};

enum e_bool
{
	FALSE,
	TRUE
};

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_line	*line;
}	t_image;

typedef struct s_cam
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_image	*image;
	t_cam	*cam;
}	t_fdf;

float	get_min(float a, float b);
float	get_max(float a, float b);
float	absolute(float n);
void	transform(t_cam *cam, t_line *line);
void	translate(t_line *line, int move_x, int move_y);
void	scale(t_line *line, int scale_factor);
void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);
void	render(t_fdf *fdf);
t_map	*read_map(char *file_name);
void	project(t_cam *cam, t_line *line);
void	print_menu(t_fdf *fdf);
int		key_handle(int keycode, t_fdf *fdf);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_map *map);
t_image	*init_image(void *mlx);
t_map	*init_map(void);
t_fdf	*init_fdf(char *file_name);
void	reset(t_fdf *fdf);
float	scale_to_fit(t_map *map);
void	center_to_origin(t_map *map);
t_point	**init_coordinates(int width, int depth);
void	error_by_code(int exit_code);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixels_to_image(t_image *image, float x, float y, int color);
void	clear_image(t_image *image, int image_size);
int		get_color(t_color *color, int i_line, int line_size);
t_color	*color_init(t_point start, t_point end);
t_color	*color_pallet_init(int min_color, int max_color);
void	close_all(t_fdf *fdf, int exit_code);
void	close_map(t_fdf *fdf, int exit_code);
int		ft_atoi_base(char *str, char *base);
size_t	split_count(const char *s, char c);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixels_to_image(t_image *image, float x, float y, int color);
void	reset_angle(t_fdf *fdf);

#endif
