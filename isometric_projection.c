/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:54:19 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 18:32:10 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric_projection(t_point a, t_vars *vars)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = ((temp_x - temp_y) * cos(vars->angle_x)) * vars->size_grid
		+ vars->offset_x;
	a.y = ((-(a.z) / vars->z_modify + (temp_x + temp_y)
				* sin(vars->angle_y))) * vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}
