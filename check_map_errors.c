/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:33 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/25 14:07:02 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_if_empty(t_vars *vars, char *line)
{
	if (line == NULL)
	{
		write (1, "Empty file. Try again please.\n", 31);
		ft_close (vars);
	}
}

int	check_if_not_digit(t_vars *vars, char *line)
{
	char	**temp;
	int		i;
	int		col_size;

	col_size = 0;
	if (!line)
		return (0);
	temp = ft_split(line, ' ');
	while (temp[col_size])
	{
		i = 0;
		while (temp[col_size][i] && temp[col_size][i] != '\n')
		{
			if (temp[col_size][i] == ',')
				break ;
			if (temp[col_size][i] == '-' && i == 0)
				i++;
			if (!ft_isdigit(temp[col_size][i]))
				free_split(temp, 1, vars);
			i++;
		}
		col_size++;
	}
	free_split(temp, 2, vars);
	return (col_size);
}

int	check_map_digits(int fd, t_vars *vars)
{
	char	*line;
	int		col_size;
	int		line_size;
	int		size_col;

	line = get_next_line(fd);
	check_if_empty(vars, line);
	col_size = check_if_not_digit(vars, line);
	line_size = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			size_col = check_if_not_digit(vars, line);
		if (col_size != size_col)
		{
			free(line);
			write (1, "Map should be either square or rectangular.\n", 45);
			exit(0);
		}
	}
	free(line);
	return (1);
}

int	check_map(t_vars *vars)
{
	int	fd;

	if (!strcmp_fdf(*vars->map_file))
	{
		write(1, "File is not a .fdf file\n", 25);
		ft_close (vars);
	}
	else
	{
		fd = open(*vars->map_file, O_RDONLY);
		if (fd == -1)
		{
			write(1, "No access to this file.\n", 25);
			ft_close (vars);
		}
		else if (check_map_digits(fd, vars))
		{
			close(fd);
			fd = open(*vars->map_file, O_RDONLY);
		}
		return (fd);
	}
	return (0);
}
