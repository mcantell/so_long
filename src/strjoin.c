/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:02 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/27 18:36:47 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		f;

	i = 0;
	f = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[f])
	{
		s[i + f] = s2[f];
		f++;
	}
	s[i + f] = '\0';
	free(s1);
	free(s2);
	return (s);
}
