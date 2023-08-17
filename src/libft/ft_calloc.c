/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:52:33 by ajari             #+#    #+#             */
/*   Updated: 2022/10/27 09:14:39 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	total;
	void	*p;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	while (i < count * size)
	{
		*(unsigned char *)(p + i) = 0;
		i++;
	}
	return (p);
}
