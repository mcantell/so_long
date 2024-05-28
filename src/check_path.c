/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 03:39:48 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/27 18:36:04 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill(char**tab, int size, int column, t_coord cur)
{
	if (cur.colum < 0 || cur.colum >= column || cur.side < 0
		|| cur.side >= size || tab[cur.side][cur.colum] == '1'
		|| tab[cur.side][cur.colum] == 'F')
		return ;
	tab[cur.side][cur.colum] = 'F';
	fill(tab, size, column, (t_coord){cur.side - 1, cur.colum});
	fill(tab, size, column, (t_coord){cur.side + 1, cur.colum});
	fill(tab, size, column, (t_coord){cur.side, cur.colum - 1});
	fill(tab, size, column, (t_coord){cur.side, cur.colum + 1});
}

int	count(t_game *smap, char c)
{
	int	i;
	int	t;
	int	index;

	i = 1;
	index = 0;
	while (smap->cmap[i] != NULL)
	{
		t = 1;
		while (smap->cmap[i][t] != '\0')
		{
			if (smap->cmap[i][t] == c)
				index++;
			t++;
		}
		i++;
	}
	return (index);
}

int	p_line(t_game *smap, char c)
{
	int	i;
	int	t;

	i = 1;
	while (smap->map[i])
	{
		t = 1;
		while (smap->map[i][t] != '\0')
		{
			if (smap->map[i][t] == c)
				return (i);
			t++;
		}
		i++;
	}
	ft_free (smap->map);
	exit (write (2, "Error\nPlayer not found\n", 24));
}

int	p_column(t_game *smap, char c, int i)
{
	int	t;

	t = 1;
	while (smap->map[i][t])
	{
		if (smap->map[i][t] == c)
			return (t);
		t++;
	}
	ft_free (smap->map);
	exit (write (2, "Error\nPlayer not found\n", 24));
}

void	check_path(t_game *smap)
{
	t_coord	p_c;
	int		c;
	int		e;

	c = 0;
	e = 0;
	p_c.side = p_line(smap, 'P');
	p_c.colum = p_column(smap, 'P', p_c.side);
	smap->cmap = matrix_copy(smap);
	fill(smap->cmap, matrix_len(smap) - 1, ft_strlen(smap->cmap[0]) - 1, p_c);
	e += count(smap, 'E');
	c += count (smap, 'C');
	if (c != 0 || e != 0)
	{
		ft_free (smap->cmap);
		ft_free (smap->map);
		exit (write (2, "Error\nroute not avaiable\n", 26));
	}
	ft_free(smap->cmap);
}