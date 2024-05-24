/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:01:13 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/24 14:50:41 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	take(char **av, t_game *c)
{
	int	flag;
	int	fd;

	flag = 0;
	fd = open(av[1], O_RDONLY);
	c->tmp = get_next_line(fd, 1);
	if (c->tmp == NULL)
		flag = 1;
	c->cont = malloc(1);
	if (c->cont == NULL)
		exit (-1);
	c->cont[0] = '\0';
	while (c->tmp != NULL)
	{
		if (c->tmp[0] == '\n')
			flag = 1;
		c->cont = ft_strjoin(c->cont, c->tmp);
		c->tmp = get_next_line(fd, 1);
	}
	if (flag == 1)
		flag = write (2, "Error\nerror on border\n", 23);
	close (fd);
	return (flag);
}

void	check_tot(char **av, t_game *c)
{
	int		flag;

	flag = 0;
	flag = take(av, c);
	if ((ft_strncmp(av[1], ".ber", 5) == 1) || flag == 1)
	{
		free (c->cont);
		exit (-1);
	}
	check_tot_1(c);
}

void	check_tot_1(t_game *c)
{
	t_game	smap;

	smap.map = ft_split(c->cont, '\n');
	free (c->cont);
	ft_shape(&smap);
	ft_border_cop(&smap);
	check_char(&smap);
	check_coll(&smap, -1);
	check_path(&smap);
	ft_free(smap.map);
}

int	main(int ac, char **av)
{
	t_game	c;

	if (ac == 2)
		check_tot(av, &c);
	return (0);
}
