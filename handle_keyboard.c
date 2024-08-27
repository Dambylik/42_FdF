/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:44:51 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 18:26:02 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keyboard(int keysym, t_vars *vars)
{
	clean_img(vars);
	if (keysym == XK_Escape)
		ft_close(vars);
	else if (keysym == 65363 || keysym == 65361
		|| keysym == 65364 || keysym == 65362)
		handle_offset(keysym, vars);
	draw_img_grid(vars);
	return (0);
}

void	handle_offset(int keysym, t_vars *vars)
{
	if (keysym == 65363)
		vars->offset_x += 50;
	else if (keysym == 65361)
		vars->offset_x -= 50;
	else if (keysym == 65364)
		vars->offset_y += 50;
	else if (keysym == 65362)
		vars->offset_y -= 50;
}
