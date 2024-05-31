/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:01:13 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/31 12:30:12 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	take(char **av, t_game *game)
{
	int	flag;
	int	fd;

	flag = 0;
	fd = open(av[1], O_RDONLY);
	game->tmp = get_next_line(fd, 1);
	if (game->tmp == NULL)
		flag = 1;
	game->cont = malloc(1);
	if (game->cont == NULL)
		exit (-1);
	game->cont[0] = '\0';
	while (game->tmp != NULL)
	{
		if (game->tmp[0] == '\n')
			flag = 1;
		game->cont = ft_strjoin(game->cont, game->tmp);
		game->tmp = get_next_line(fd, 1);
	}
	if (flag == 1)
		return (flag = write (2, "Error\nerror on border\n", 23));
	close (fd);
	return (flag);
}

void	check_tot(char **av, t_game *game)
{
	int		flag;

	flag = 0;
	flag = take(av, game);
	if (flag == 23)
	{
		free (game->cont);
		exit(-1);
	}
	if ((ft_strncmp(av[1], ".ber", 5) == 1) || flag == 1)
	{
		free (game->cont);
		exit (-1);
	}
	check_tot_1(game);
}

void	check_tot_1(t_game *game)
{
	game->map = ft_split(game->cont, '\n');
	free (game->cont);
	ft_shape(game);
	ft_border_cop(game);
	check_char(game);
	check_coll(game, -1);
	check_path(game);
}

int	main(int ac, char **av)
{
	t_mlxs	s;

	if (ac == 2)
	{
		val_init(&s);
		check_tot(av, &(s.game));
		s.mlx_ptr = mlx_init();
		if (!s.mlx_ptr)
			exit (-1);
		texture(&s);
		display(&s);
		mlx_hook(s.mlx_win, ON_DESTROY, 0, close_wind, &s);
		mlx_hook(s.mlx_win, 2, 1L << 0, keymove, &s);
		mlx_loop(s.mlx_ptr);
		ft_free(s.game.map);
	}
	return (0);
}
