/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:37:53 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 19:12:04 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include "X11/keysym.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1060

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct s_screen
{
	int		min_x;
	int		min_y;
	int		max_y;
	int		max_x;
}				t_screen;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			**map;
	int			nb_lines;
	int			nb_cols;
	float		size_grid;
	int			offset_x;
	int			offset_y;
	float		angle_x;
	float		angle_y;
	int			max_z;
	int			min_z;
	int			map_option;
	t_data		img;
	t_point		**point_map;
	int			new_max;
	float		z_modify;
	char		**map_file;
	t_screen	screen;
	float		range_z;
	float		slope;
	int			direction;
}				t_vars;

char	*get_next_line(int fd);
void	map_loading(t_vars *vars, int fd, int index);
void	ft_max_and_min(int nb, t_vars *vars);
void	ft_set_variables(t_vars *vars);
t_point	init_point(int x, int y, int z);
t_point	isometric_projection(t_point a, t_vars *vars);
void	transform_map_to_points(t_vars *vars);
void	draw_img_grid(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		handle_keyboard(int keysym, t_vars *vars);
void	screen_size(t_vars *vars);
void	handle_offset(int keysym, t_vars *vars);
int		ft_close(void *o);
void	clean_img(t_vars *vars);
void	free_map(t_vars *vars);
void	choose_map(t_vars *vars);
int		check_map(t_vars *vars);
void	free_split(char **temp, int opt, t_vars *vars);
int		strcmp_fdf(char *a);

#endif
