/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:01:13 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/23 14:50:05 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_tot(char **av, t_game *c)
{
	int		fd;
	char	*tmp;

	if ((ft_strncmp(av[1], ".ber", 5) != 0))
		exit (write (2, "Error\nmap not .ber\n", 19));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit (write (2, "Error\n error open\n", 19));
	tmp = get_next_line(fd);
	if (tmp == NULL)
		exit (write (2, "Error\nmap not found\n", 21));
	c->cont = malloc(1);
	if (!c->cont)
		exit(-1);
	c->cont[0] = '\0';
	while (tmp != NULL)
	{
		if (*tmp == '\n')
			return (free(c->cont), free(tmp),
		exit (write (2, "Error\nerror border wide open\n", 30)));
		c->cont = ft_strjoin(c->cont, tmp);
		tmp = get_next_line(fd);
	}
	close (fd);
	check_tot_1(c);
}

void	check_tot_1(t_game *c)
{
	t_game	smap;

	smap.map = ft_split(c->cont, '\n');
	ft_shape(&smap);
	ft_border_cop(&smap);
	check_char(&smap);
	check_coll(&smap);
	check_path(&smap);
	ft_free(smap.map);
	free(c->cont);
}

int	main(int ac, char **av)
{
	t_game	c;

	if (ac == 2)
		check_tot(av, &c);
	return (0);
}
