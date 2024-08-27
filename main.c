/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:50:07 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 18:33:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	choose_map(t_vars *vars)
{
	int	fd;

	fd = check_map(vars);
	ft_set_variables(vars);
	map_loading(vars, fd, 0);
	transform_map_to_points(vars);
	screen_size(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = \
		mlx_new_image(vars->mlx, vars->screen.max_x, vars->screen.max_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->win = mlx_new_window(vars->mlx, \
		vars->screen.max_x, vars->screen.max_y, "FdF - OLGA");
	mlx_hook(vars->win, 2, 1L << 0, handle_keyboard, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	draw_img_grid(vars);
}

int	main(int argc, char **argv)
{
	static t_vars	vars;

	if (argc == 1)
		write(1, "Error! Not enough arguments!\n", 30);
	if (argc > 2)
		write(1, "Error! Wrong number of arguments!\n", 35);
	if (argc == 2)
	{
		vars.mlx = mlx_init();
		vars.map_file = &argv[1];
		choose_map(&vars);
		mlx_loop(vars.mlx);
	}
}
