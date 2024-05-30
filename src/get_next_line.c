/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:00:06 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/27 18:36:28 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*legge_la_linea(int fd, char *left_line)
{
	char		*buf;
	int			number_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	number_byte = 1;
	while (!ft_strachr(left_line, '\n') && number_byte != 0)
	{
		number_byte = read(fd, buf, BUFFER_SIZE);
		if (number_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[number_byte] = '\0';
		left_line = ft_strjoint(left_line, buf);
	}
	free(buf);
	return (left_line);
}

char	*get_next_line(int fd, int i)
{
	char		*linea;
	static char	*left_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (exit (write (2, "Error\nerror open\n", 18)), NULL);
	left_line = legge_la_linea(fd, left_line);
	if (!left_line)
		return (NULL);
	linea = prendi(left_line);
	left_line = checkpoint(left_line);
	if (i == 0)
	{
		free(linea);
		free (left_line);
		i = write (2, "Error\nerror border wide open\n", 30);
	}
	return (linea);
}
