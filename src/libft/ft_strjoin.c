/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:30:07 by ajari             #+#    #+#             */
/*   Updated: 2023/03/27 13:45:18 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memset((void *)sub, 0, len);
	if (s1)
	{
		ft_strlcpy(sub, s1, len + 1);
		free((void *)s1);
		s1 = 0;
	}
	if (s2)
	{
		ft_strlcat(sub, s2, len + 1);
		free((void *)s2);
		s2 = 0;
	}
	return (sub);
}
