/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:02:54 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/25 12:41:19 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_variables(t_vars *vars)
{
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->size_grid = 50;
	vars->angle_y = 0.523599;
	vars->angle_x = 0.523599;
	vars->z_modify = 1;
	vars->screen.max_x = 0;
	vars->screen.min_x = 0;
	vars->screen.max_y = 0;
	vars->screen.min_y = 0;
	vars->max_z = 0;
	vars->min_z = 0;
	vars->map_option = 1;
}

void	bigger_screen(t_vars *vars)
{
	while ((vars->screen.max_x > WINDOW_WIDTH || \
		vars->screen.max_x > WINDOW_HEIGHT))
	{
		vars->screen.max_y /= 2;
		vars->screen.max_x /= 2;
		vars->offset_x = abs(vars->offset_x / 2);
		vars->offset_y = abs(vars->offset_y / 2);
		vars->size_grid /= 2;
		if (vars->size_grid < 1)
		{
			if (vars->screen.max_y > WINDOW_HEIGHT)
				vars->screen.max_y = WINDOW_HEIGHT;
			if (vars->screen.max_x > WINDOW_WIDTH)
				vars->screen.max_x = WINDOW_WIDTH;
			break ;
		}
	}
}

void	smaller_screen(t_vars *vars)
{
	while ((vars->screen.max_x < WINDOW_WIDTH / 5 \
	|| vars->screen.max_x < WINDOW_HEIGHT / 5))
	{
		vars->screen.max_y *= 3;
		vars->screen.max_x *= 3;
		vars->offset_x = abs(vars->offset_x * 3);
		vars->offset_y = abs(vars->offset_y * 3);
		vars->size_grid *= 3;
	}
}

void	screen_size(t_vars *vars)
{
	int	diff_x;
	int	diff_y;

	diff_x = WINDOW_WIDTH - vars->screen.max_x;
	diff_y = WINDOW_HEIGHT - vars->screen.max_x;
	vars->screen.max_x = vars->screen.max_x - vars->screen.min_x;
	vars->screen.max_y = vars->screen.max_y - vars->screen.min_y;
	vars->offset_x = -vars->screen.min_x;
	vars->offset_y = -vars->screen.min_y;
	if (diff_x < 0 || diff_y < 0)
		bigger_screen(vars);
	else
		smaller_screen(vars);
	if (vars->map_option == 1)
	{
		vars->offset_x = WINDOW_WIDTH / 2 \
			- vars->screen.max_x / 2 + vars->offset_x;
		vars->offset_y = WINDOW_HEIGHT / 2 \
			- vars->screen.max_y / 2 + vars->offset_y;
		vars->screen.max_x = WINDOW_WIDTH;
		vars->screen.max_y = WINDOW_HEIGHT;
	}
}
