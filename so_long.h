/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:45:20 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/13 16:07:26 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"

typedef struct s_game
{
	char	**map;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		cc;
	int		cp;
	int		ce;
}	t_game;

int		ft_strlen(char *str);
int		ft_strncmp(const char *str1, const char *str2, int s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		matrix_len(t_game *smap);
void	ft_border_cop(t_game *smap);
void	ft_shape(t_game *smap);
int		check_coll(t_game *smap);

#endif