/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:17:34 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/25 13:30:53 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	init_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	ft_max_and_min(int nb, t_vars *vars)
{	
	if (!vars->max_z || nb > vars->max_z)
	{
		vars->max_z = nb;
	}
	if (!vars->min_z || nb < vars->min_z)
		vars->min_z = nb;
}

int	*split_array(t_vars *vars, char *line)
{
	int		*t;
	char	**temp;
	int		size;
	int		i;

	size = 0;
	i = 0;
	temp = ft_split(line, ' ');
	while (temp[size])
		size++;
	vars->nb_cols = size;
	t = malloc(sizeof(int) * size);
	if (!t)
		return (0);
	while (i < size)
	{
		t[i] = ft_atoi(temp[i]);
		ft_max_and_min(t[i], vars);
		free(temp[i]);
		i++;
	}
	free(temp);
	return (t);
}

void	map_loading(t_vars *vars, int fd, int index)
{
	char	*line;

	line = get_next_line(fd);
	vars->nb_lines++;
	if (line)
		map_loading(vars, fd, index + 1);
	else
	{
		vars->map = malloc(sizeof(int *) * vars->nb_lines);
		if (!vars->map)
			return ;
	}	
	if (line)
		vars->map[index] = split_array(vars, line);
	else
		vars->map[index] = (int *)line;
	free(line);
}
