/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:54 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/30 12:48:25 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_border_cop(t_game *smap)
{
	int	i;
	int	t;

	t = 0;
	i = matrix_len(smap) - 1;
	while (smap->map[0][t] != '\0')
	{
		if (smap->map[i][t] != '1' || smap->map[0][t] != '1')
			return (ft_free(smap->map),
				exit (write (2, "Error\nerror border open\n", 25)));
		t++;
	}
	if (i != 1)
	{
		i = 1;
		while (smap->map[i])
		{
			t = ft_strlen(smap->map[i]) - 1;
			if (smap->map[i][0] != '1' || smap->map[i][t] != '1')
				return (ft_free(smap->map),
					exit (write (2, "Error\nerror border open\n", 25)));
			i++;
		}
	}
}

void	ft_shape(t_game *smap)
{
	int	i;
	int	t;

	i = matrix_len(smap) - 1;
	t = ft_strlen(smap->map[i]) - 1;
	if (i == t)
	{
		i = write(2, "Error\ndo you know the difference between ", 42);
		return (ft_free (smap->map),
			exit (write (2, "a rectangle and the other shapes?", 33)));
	}
	else
	{
		i = 1;
		while (i != matrix_len(smap))
		{
			if (ft_strlen(smap->map[i]) - 1 != ft_strlen(smap->map[i - 1]) - 1)
			{
				i = write(2, "Error\ndo you know the difference between ", 42);
				return (ft_free (smap->map),
					exit (write (2, "a rectangle and the other shapes?", 33)));
			}
			i++;
		}
	}
}

int	check_coll(t_game *smap, int i)
{
	int	t;

	smap->cc = 0;
	smap->cp = 0;
	smap->ce = 0;
	while (smap->map[++i])
	{
		t = 0;
		while (smap->map[i][t])
		{
			if (smap->map[i][t] == 'C')
				smap->cc++;
			else if (smap->map[i][t] == 'P')
				smap->cp++;
			else if (smap->map[i][t] == 'E')
				smap->ce++;
			t++;
		}
	}
	if (smap->cc == 0 || smap->cp > 1 || smap->ce > 1)
	{
		ft_free (smap->map);
		exit (write (2, "Error\nerror inside the map", 27));
	}
	return (smap->cc);
}

void	check_char(t_game *smap)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (smap->map[i])
	{
		t = 0;
		while (smap->map[i][t])
		{
			if (smap->map[i][t] != 'C' && smap->map[i][t] != 'P' &&
				smap->map[i][t] != 'E' && smap->map[i][t] != '1' &&
				smap->map[i][t] != '0')
				return (ft_free (smap->map),
					exit (write (2, "Error\nunwanted character", 25)));
			t++;
		}
		i++;
	}
}
