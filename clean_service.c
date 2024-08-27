/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_service.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:25:49 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 18:27:37 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map && vars->map[++i])
	{
		free(vars->map[i]);
		free(vars->point_map[i]);
	}
	free(vars->map);
	free(vars->point_map);
	vars->map = NULL;
	vars->point_map = NULL;
}

void	clean_img(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->screen.max_x)
	{
		j = -1;
		while (++j < vars->screen.max_y)
			my_mlx_pixel_put(vars, i, j, 0x00000000);
	}
}

void	free_mlx(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	ft_close(void *o)
{
	free_map((t_vars *) o);
	free_mlx((t_vars *) o);
	exit(0);
	return (0);
}
