/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:54 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/10 15:14:24 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_border_cop(t_game *smap)
{
	int	i;
	int	t;

	t = 0;
	i = matrix_len(smap) - 1;
	while (smap->map[0][t] != '\0')
	{
		if (smap->map[i][t] != '1' || smap->map[0][t] != '1')
			exit (write (2, "Error\nerror border open", 24));
		t++;
	}
	if (i != 1)
	{
		i = 1;
		t = ft_strlen(smap->map[i]) - 1;
		while (smap->map[i])
		{
			if (smap->map[i][0] != '1' || smap->map[i][t] != '1')
				exit (write (2, "Error\nerror border open", 24));
			i++;
		}
	}
}
