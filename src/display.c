/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:21:20 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/31 12:30:02 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display(t_mlxs *s)
{
	s->wind.windl = (ft_strlen(s->game.map[0]) * TILE_SIZE);
	s->wind.winda = (matrix_len(&(s->game)) * TILE_SIZE);
	s->mlx_win = mlx_new_window(s->mlx_ptr, s->wind.windl,
			s->wind.winda, DISPLAY_NAME);
	print(s);
}

int	close_wind(t_mlxs *s)
{
	mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	free (s->mlx_ptr);
	ft_free(s->game.map);
	exit (0);
}

void	texture(t_mlxs *s)
{
	s->witdh = 0;
	s->height = 0;
	s->floor = mlx_xpm_file_to_image(s->mlx_ptr, "texture/floor.xpm",
			&s->witdh, &s->height);
	s->collect = mlx_xpm_file_to_image(s->mlx_ptr, "texture/stimpak.xpm",
			&s->witdh, &s->height);
	s->exit = mlx_xpm_file_to_image(s->mlx_ptr, "texture/vault_door.xpm",
			&s->witdh, &s->height);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, "texture/wall.xpm",
			&s->witdh, &s->height);
	s->player = mlx_xpm_file_to_image(s->mlx_ptr, "texture/armor.xpm",
			&s->witdh, &s->height);
}
