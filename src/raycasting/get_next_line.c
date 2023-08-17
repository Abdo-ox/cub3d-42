/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:54:07 by ajari             #+#    #+#             */
/*   Updated: 2023/06/16 00:16:01 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_clear(char *ptr, char *s)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		ptr[i] = 0;
		i++;
	}
	free((void *)s);
	return (0);
}

char	*ft_free(char *ptr, char *s)
{
	if (ptr)
		free(ptr);
	free(s);
	return (0);
}

char	*ft_line(char **ptr)
{
	char	*tmp;
	char	*line;
	int		i;

	line = 0;
	i = ft_strchr_index(*ptr, '\n');
	if (i)
	{
		line = ft_substr(*ptr, 0, i);
		tmp = *ptr;
		*ptr = ft_strdup(*ptr + i + 1);
		free(tmp);
	}
	return (line);
}

char	*ft_fill(char **ptr, int fd)
{
	char	*s;
	char	*t;
	int		m;
	size_t	k;

	m = 1;
	k = 1;
	s = malloc(BUFFER_SIZE + k);
	if (!s)
		return (0);
	while (ft_strchr_index(*ptr, '\n') < 0)
	{
		m = read(fd, s, BUFFER_SIZE);
		if (m == 0 && *ptr)
			return (free(s), t = *ptr, *ptr = 0, t);
		if ((m == 0 && !*ptr) || m == -1)
			return (ft_clear(*ptr, s));
		s[m] = '\0';
		*ptr = ft_strjoin(*ptr, s);
	}
	return (free(s), ft_line(ptr));
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			i;
	char		*tmp;

	if (BUFFER_SIZE >= SIZE_MAX || BUFFER_SIZE <= 0)
		return (0);
	i = ft_strchr_index(ptr, '\n');
	if (ptr && *ptr && i)
	{
		tmp = ptr;
		line = ft_substr(ptr, 0, i);
		ptr = ft_strdup(ptr + i + 1);
		free(tmp);
	}
	else
		line = ft_fill(&ptr, fd);
	return (line);
}
