/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:51:25 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/13 12:01:56 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**matrix_copy(t_game *smap)
{
	char	**cmap;
	int		i;

	i = matrix_len(smap) - 1;
	cmap = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (smap->map[i] != NULL)
	{
		cmap[i] = smap->map[i];
		i++;
	}
	return (cmap);
}
