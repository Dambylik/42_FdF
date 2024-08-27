/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:41:20 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:41:22 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int p)
{
	if ((p >= 65 && p <= 90) || (p >= 97 && p <= 122) || (p >= '0' && p <= '9'))
		return (1);
	return (0);
}