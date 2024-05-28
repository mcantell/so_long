/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:21:20 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/28 13:07:07 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display(t_mlxs *s)
{
	s->wind.windl = (ft_strlen(s->game.map[0]) * TILE_SIZE);
	s->wind.winda = (matrix_len(&(s->game)) * TILE_SIZE);
	s->mlx_win = mlx_new_window(s->mlx_ptr, s->wind.windl,
			s->wind.winda, DISPLAY_NAME);
}

int	close_wind(void *ser)
{
	t_mlxs	*s;

	s = ser;
	mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	free (s->mlx_ptr);
	ft_free(s->game.map);
	exit (0);
}
