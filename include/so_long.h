/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:45:20 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/30 12:33:59 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# define TILE_SIZE 100
# define DISPLAY_NAME "Sergio"
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"

# define ON_DESTROY 17

# define KEY_ARROW_RIGHT 65363
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_UP 65362
# define KEY_ARROW_DOWN 65364

# define KEY_D 100
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115

# define KEY_ESC 65307

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
	void		*floor;
	void		*wall;
	void		*player;
	void		*collect;
	void		*exit;
	int			witdh;
	int			height;
	int			move;
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
int		close_wind(t_mlxs *s);
void	texture(t_mlxs	*s);
void	print_map(t_mlxs *s, int i, int t);
void	print(t_mlxs *s);
void	ft_putnbr(int n);
void	move_w(t_mlxs	*s);
int		keymove(int i, void *c);
void	move_a(t_mlxs	*s);
void	move_s(t_mlxs	*s);
void	move_d(t_mlxs	*s);
void	val_init(t_mlxs *s);
#endif
