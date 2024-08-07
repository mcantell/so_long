/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:28:00 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/27 18:36:37 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	matrix_len(t_game *smap)
{
	int	i;

	i = 0;
	while (smap->map[i])
		i++;
	return (i);
}
