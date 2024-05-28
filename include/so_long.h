/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:45:20 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/28 12:22:54 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# define TILE_SIZE 64
# define DISPLAY_NAME "Sergio"
# include "../mlx/mlx.h"
# define ON_DESTROY 17

typedef struct s_coord
{
	int	side;
	int	colum;
}	t_coord;

typedef struct s_game
{
	char	**map;
	char	**cmap;
	char	*cont;
	char	*tmp;
	int		cc;
	int		cp;
	int		ce;
}	t_game;

typedef struct s_display
{
	int	windl;
	int	winda;
}	t_display;

typedef struct s_mlxs
{
	t_coord		coordinate;
	t_display	wind;
	t_game		game;
	void		*mlx_ptr;
	void		*mlx_win;
}	t_mlxs;

int		ft_strlen(char *str);
int		ft_strncmp(const char *str1, const char *str2, int s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		matrix_len(t_game *smap);
void	ft_border_cop(t_game *smap);
void	ft_shape(t_game *smap);
int		check_coll(t_game *smap, int i);
void	check_path(t_game *smap);
int		p_column(t_game *smap, char c, int i);
int		p_line(t_game *smap, char c);
int		count(t_game *cmap, char c);
void	fill(char **tab, int size, int column, t_coord cur);
void	check_char(t_game *smap);
void	free_matrix(char **cmap);
void	ft_free(char **str);
char	**matrix_copy(t_game *smap);
char	*ft_strdup(char *s1);
void	check_tot_1(t_game *c);
void	check_tot(char **av, t_game *c);
int		take(char **av, t_game *c);
void	display(t_mlxs *s);
int		close_wind(void *ser);
#endif
