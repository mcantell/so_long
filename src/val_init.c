/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:25:01 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/30 12:32:55 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	val_init(t_mlxs *s)
{
	s->mlx_ptr = NULL;
	s->mlx_win = NULL;
	s->floor = NULL;
	s->wall = NULL;
	s->player = NULL;
	s->collect = NULL;
	s->exit = NULL;
	s->witdh = 0;
	s->height = 0;
	s->move = 0;
	s->coordinate.side = 0;
	s->coordinate.colum = 0;
	s->game.cc = 0;
	s->game.ce = 0;
	s->game.cp = 0;
	s->game.cmap = NULL;
	s->game.cont = NULL;
	s->game.map = NULL;
	s->game.tmp = NULL;
	s->wind.winda = 0;
	s->wind.winda = 0;
}
