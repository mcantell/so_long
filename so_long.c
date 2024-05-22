/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:01:13 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/22 14:19:52 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	smap;
	int		fd;
	char	*tmp;
	char	*cont;

	cont = malloc(1);
	if (cont == NULL)
		return (-1);
	*cont = '\0';
	if (ac == 2)
	{
		if ((ft_strncmp(av[1], ".ber", 5) != 0))
			exit (write (2, "Error\nmap not .ber\n", 19));
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit (write (2, "Error\n error open\n", 19));
		tmp = get_next_line(fd);
		if (tmp == NULL)
			exit (write (2, "Error\nmap not found\n", 21));
		while (tmp != NULL)
		{
			if (*tmp == '\n')
				exit (write (2, "Error\nerror border wide open\n", 30));
			cont = ft_strjoin(cont, tmp);
			tmp = get_next_line(fd);
		}
		smap.map = ft_split(cont, '\n');
		ft_shape(&smap);
		ft_border_cop(&smap);
		check_char(&smap);
		check_coll(&smap);
		check_path(&smap);
		close (fd);
	}
	return (0);
}
