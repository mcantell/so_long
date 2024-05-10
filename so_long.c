/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:01:13 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/10 15:26:41 by mcantell         ###   ########.fr       */
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
			exit (write (2, "Error\n map not .ber\n", 20));
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit (write (2, "Error\n error open\n", 19));
		tmp = get_next_line(fd);
		while (tmp != NULL)
		{
			if (*tmp == '\n')
				exit (write (2, "Error\nerror border wide open\n", 30));
			cont = ft_strjoin(cont, tmp);
			tmp = get_next_line(fd);
		}
		smap.map = ft_split(cont, '\n');
		for (int i=0; smap.map[i] != NULL;i++)
			printf("%s\n", smap.map[i]);
		ft_border_cop(&smap);
		close (fd);
	}
	return (0);
}
