/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:00:35 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/23 14:47:01 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strachr(char *left_line, int c)
{
	int	i;

	i = 0;
	if (!left_line)
		return (NULL);
	if (c == '\0')
		return (left_line);
	while (left_line[i])
	{
		if (left_line[i] == (char)c)
			return (left_line);
		i++;
	}
	return (0);
}

char	*ft_strjoint(char *left_line, char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!left_line)
	{
		left_line = (char *)malloc(sizeof(char) * 1);
		left_line[0] = '\0';
	}
	if (!left_line || !buf)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((len(left_line) + len(buf) + 1)));
	if (!str)
		return (NULL);
	if (left_line)
		while (left_line[++i])
			str[i] = left_line[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[len(left_line) + len(buf)] = '\0';
	free(left_line);
	return (str);
}

char	*prendi(char *left_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!*left_line)
		return (NULL);
	while (left_line[i] && left_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_line[i] && left_line[i] != '\n')
	{
		str[i] = left_line[i];
		i++;
	}
	if (left_line[i] == '\n')
	{
		str[i] = left_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*checkpoint(char *left_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (left_line[i] && left_line[i] != '\n')
		i++;
	if (!left_line[i])
	{
		free(left_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (len(left_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (left_line[i])
		str[j++] = left_line[i++];
	str[j] = '\0';
	free(left_line);
	return (str);
}
