/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:22:52 by ajari             #+#    #+#             */
/*   Updated: 2023/04/07 01:25:50 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	v;
	int		m;
	int		i;

	i = 0;
	m = 1;
	v = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		v = v * 10 + (str[i++] - 48);
		if (v >= LONG_MAX && m == 1)
			return (-1);
		if (v > LONG_MAX && m == -1)
			return (0);
	}
	return ((v * m));
}
