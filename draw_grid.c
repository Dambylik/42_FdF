/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:34:23 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 19:12:50 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || y < 0 || x >= vars->screen.max_x || y >= vars->screen.max_y))
	{
		dst = vars->img.addr + (y * vars->img.line_length + \
		x * (vars->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	initiate_point(t_vars *vars, t_point a, t_point b)
{
	if (b.z - a.z > 0)
		vars->range_z = (b.z / vars->new_max);
	else
		vars->range_z = -(a.z / vars->new_max - b.z);
	vars->slope = (b.y - a.y) / (b.x - a.x);
	vars->direction = (b.x - a.x) / (fabs(b.x - a.x));
}

void	connect_two_points(t_vars *vars, t_point a, t_point b)
{
	float	x;
	float	y;

	a = isometric_projection(a, vars);
	b = isometric_projection(b, vars);
	x = a.x;
	initiate_point(vars, a, b);
	while (fabs(b.x - x) > 0.5)
	{
		y = vars->slope * (x - a.x) + a.y;
		my_mlx_pixel_put(vars, x, y, 0xFFFFFF);
		x += vars->direction;
	}
}

void	draw_img_grid(t_vars *vars)
{
	int	x;
	int	y;
	int	y_new;

	y = -1;
	while (++y < vars->nb_lines - 1)
	{
		x = 0;
		while (x < vars->nb_cols)
		{
			y_new = vars->nb_lines - 2 - y;
			if (x < vars->nb_cols - 1)
				connect_two_points(vars, (vars->point_map)[y_new][x], \
				(vars->point_map)[y_new][x + 1]);
			if (y < vars->nb_lines - 2)
				connect_two_points(vars, (vars->point_map)[y_new][x], \
				(vars->point_map)[y_new - 1][x]);
			x++;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
