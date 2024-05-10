/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:18:58 by mcantell          #+#    #+#             */
/*   Updated: 2024/05/10 11:46:10 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *str1, const char *str2, int s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	i = ft_strlen((char *)str1) - 4;
	while (i > 0)
	{
		str1++;
		i--;
	}
	while (*str1 == *str2 && *str1 && s > -1)
	{
		str1++;
		str2++;
		s--;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

static int	ft_count(const char *str, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*f;
	size_t	t;
	size_t	i;

	t = 0;
	i = 0;
	if (!s || len <= 0)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
		len = 0;
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	f = (char *)malloc(sizeof(char) * (len + 1));
	if (!f)
		return (NULL);
	while (s[t])
	{
		if (t >= start && i < len)
			f[i++] = s[t];
		t++;
	}
	f[i] = '\0';
	return (f);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	f;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			f = 1;
			while (*s && *s != c && f++)
				s++;
			str[i] = ft_substr(s - f + 1, 0, f - 1);
			i++;
		}
		else
			s++;
	}
	str[i] = (NULL);
	return (str);
}
