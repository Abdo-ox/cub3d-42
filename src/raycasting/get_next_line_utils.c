/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:42:36 by ajari             #+#    #+#             */
/*   Updated: 2023/06/07 17:02:16 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	if (!p[0])
	{
		free(p);
		return (0);
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	l_total;
	size_t	i;
	size_t	j;

	l_total = ft_strlen(s1) + ft_strlen(s2);
	sub = malloc(l_total + 1);
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		sub[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		sub[i + j] = s2[j];
		j++;
	}
	sub[j + i] = '\0';
	if (s1)
		free((void *)s1);
	return (sub);
}

int	ft_strchr_index(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	char	*sub;

	i = 0;
	sub = NULL;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens || len == 0)
		return (ft_strdup(""));
	if (lens - start < len)
		len = lens - start;
	sub = malloc(len + 1);
	if (sub)
	{
		while (i < len && s[i])
		{
			sub[i] = s[i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
