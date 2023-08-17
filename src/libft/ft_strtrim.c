/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:26:26 by ajari             #+#    #+#             */
/*   Updated: 2023/04/05 12:46:15 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_m1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s)
		i++;
	return (i);
}

static int	ft_start(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	if (!set)
		return (-1);
	while (s1 && s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set, size_t len_s1)
{
	int	j;

	while (len_s1 > 0 && set)
	{
		len_s1--;
		j = 0;
		while (set[j])
		{
			if (s1[len_s1] == set[j])
				break ;
			j++;
		}
		if (set[j] == 0)
			break ;
	}
	return (len_s1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;
	int		i;

	if (!s1)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set, ft_strlen_m1(s1));
	if (end <= start)
		return (ft_strdup(""));
	p = malloc(end - start + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i + start < end && s1[start + i])
	{
		p[i] = s1[start + i];
		i++;
	}
	if (s1)
		free((void *)s1);
	p[i] = 0;
	return (p);
}
