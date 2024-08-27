/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:20:21 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/24 18:20:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	strcmp_fdf(char *a)
{
	int		i;
	int		j;
	char	*b;

	b = ".fdf";
	i = 0;
	j = -1;
	while (a[i] != 0)
		i++;
	i -= 5;
	while (a[++i] != 0)
	{
		if (a[i] != b[++j])
			return (0);
	}
	return (1);
}

void	free_split(char **temp, int opt, t_vars *vars)
{
	int	i;

	if (opt == 1)
	{
		write (1, "Map contains a non-digit character!\n", 22);
		ft_close (vars);
	}
	if (opt == 2)
	{
		i = 0;
		while (temp[i])
			free(temp[i++]);
		free(temp);
	}
}
