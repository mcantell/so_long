/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:31:16 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/28 17:51:13 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print(t_mlxs *s)
{
	int	i;
	int	t;

	i = 0;
	mlx_clear_window(s->mlx_ptr, s->mlx_win);
	while (s->game.map[i] != NULL)
	{
		t = 0;
		while (s->game.map[i][t] != '\0')
		{
			print_map(s, i , t);
			t++;
		}
		i++;
	}
}

void	print_map(t_mlxs *s, int i, int t)
{
	texture(s);
	if (s->game.map[i][t] == '1')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->wall, t * 100,
		i * 100);
	if (s->game.map[i][t] == 'P')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->player, t * 100,
		i * 100);
	else if (s->game.map[i][t] == 'E')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->exit, t * 100,
		i * 100);
	else if (s->game.map[i][t] == '0')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->floor, t * 100,
		i * 100);
	else if (s->game.map[i][t] == 'C')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->collect, t * 100,
		i * 100);
}
