/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:02:58 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/22 14:16:41 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	**matrix_copy(t_game *smap)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (matrix_len(smap) + 1));
	if (!copy)
	{
		free(copy);
		exit (-1);
	}
	while (smap->map[i] != NULL)
	{
		copy[i] = ft_strdup(smap->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
