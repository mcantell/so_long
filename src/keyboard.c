/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:05:11 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/31 12:31:17 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_w(t_mlxs	*s)
{
	s->coordinate.side = p_line(&(s->game), 'P');
	s->coordinate.colum = p_column(&(s->game), 'P', s->coordinate.side);
	if (s->game.map[s->coordinate.side - 1][s->coordinate.colum] != '1')
	{
		if (s->game.map[s->coordinate.side - 1][s->coordinate.colum] == 'C')
			s->game.cc--;
		if (s->game.map[s->coordinate.side - 1][s->coordinate.colum] == 'E' &&
		s->game.cc == 0)
		{
			ft_free(s->game.map);
			s->move++;
			ft_printf("Move did :%d\n", s->move++);
			exit (0);
		}
		if (s->game.map[s->coordinate.side - 1][s->coordinate.colum] == 'E' &&
		s->game.cc != 0)
			return ;
		s->game.map[s->coordinate.side - 1][s->coordinate.colum] = 'P';
		s->game.map[s->coordinate.side][s->coordinate.colum] = '0';
		s->coordinate.side--;
		s->move++;
		write (1, "Move did :", 11);
		ft_printf("%d\n", s->move);
	}
}

void	move_a(t_mlxs	*s)
{
	s->coordinate.side = p_line(&(s->game), 'P');
	s->coordinate.colum = p_column(&(s->game), 'P', s->coordinate.side);
	if (s->game.map[s->coordinate.side][s->coordinate.colum - 1] != '1')
	{
		if (s->game.map[s->coordinate.side][s->coordinate.colum - 1] == 'C')
			s->game.cc--;
		if (s->game.map[s->coordinate.side][s->coordinate.colum - 1] == 'E' &&
		s->game.cc == 0)
		{
			ft_free(s->game.map);
			s->move++;
			ft_printf("Move did :%d\n", s->move++);
			exit (0);
		}
		if (s->game.map[s->coordinate.side][s->coordinate.colum - 1] == 'E' &&
		s->game.cc != 0)
			return ;
		s->game.map[s->coordinate.side][s->coordinate.colum - 1] = 'P';
		s->game.map[s->coordinate.side][s->coordinate.colum] = '0';
		s->coordinate.colum--;
		s->move++;
		write (1, "Move did :", 11);
		ft_printf("%d\n", s->move);
	}
}

void	move_s(t_mlxs	*s)
{
	s->coordinate.side = p_line(&(s->game), 'P');
	s->coordinate.colum = p_column(&(s->game), 'P', s->coordinate.side);
	if (s->game.map[s->coordinate.side + 1][s->coordinate.colum] != '1')
	{
		if (s->game.map[s->coordinate.side + 1][s->coordinate.colum] == 'C')
			s->game.cc--;
		if (s->game.map[s->coordinate.side + 1][s->coordinate.colum] == 'E' &&
		s->game.cc == 0)
		{
			ft_free(s->game.map);
			s->move++;
			ft_printf("Move did :%d\n", s->move++);
			exit (0);
		}
		if (s->game.map[s->coordinate.side + 1][s->coordinate.colum] == 'E' &&
		s->game.cc != 0)
			return ;
		s->game.map[s->coordinate.side + 1][s->coordinate.colum] = 'P';
		s->game.map[s->coordinate.side][s->coordinate.colum] = '0';
		s->coordinate.side++;
		s->move++;
		write (1, "Move did :", 11);
		ft_printf("%d\n", s->move);
	}
}

void	move_d(t_mlxs	*s)
{
	s->coordinate.side = p_line(&(s->game), 'P');
	s->coordinate.colum = p_column(&(s->game), 'P', s->coordinate.side);
	if (s->game.map[s->coordinate.side][s->coordinate.colum + 1] != '1')
	{
		if (s->game.map[s->coordinate.side][s->coordinate.colum + 1] == 'C')
			s->game.cc--;
		if (s->game.map[s->coordinate.side][s->coordinate.colum + 1] == 'E' &&
		s->game.cc == 0)
		{
			ft_free(s->game.map);
			s->move++;
			ft_printf("Move did :%d\n", s->move);
			exit (0);
		}
		if (s->game.map[s->coordinate.side][s->coordinate.colum + 1] == 'E' &&
		s->game.cc != 0)
			return ;
		s->game.map[s->coordinate.side][s->coordinate.colum + 1] = 'P';
		s->game.map[s->coordinate.side][s->coordinate.colum] = '0';
		s->coordinate.colum++;
		s->move++;
		write (1, "Move did :", 11);
		ft_printf("%d\n", s->move);
	}
}

int	keymove(int i, void *c)
{
	t_mlxs	*s;

	s = c;
	if (i == KEY_W || i == KEY_ARROW_UP)
		move_w(s);
	if (i == KEY_A || i == KEY_ARROW_LEFT)
		move_a(s);
	if (i == KEY_D || i == KEY_ARROW_RIGHT)
		move_d(s);
	if (i == KEY_S || i == KEY_ARROW_DOWN)
		move_s(s);
	if (i == KEY_ESC)
	{
		ft_free(s->game.map);
		exit (0);
	}
	print(s);
	return (1);
}
