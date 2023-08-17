/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:28:46 by ajari             #+#    #+#             */
/*   Updated: 2022/10/31 12:44:13 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power(int base, int expo)
{
	int	i;
	int	pow;

	i = 0;
	pow = 1;
	while (i < expo)
	{
		pow = pow * base;
		i++;
	}
	return (pow);
}

static char	*ft_fil_s(char *s, int n, int pow, int digit)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		free(s);
		return (ft_strdup("0"));
	}
	while (i < digit - 1)
	{
		s[i] = n / pow + 48;
		n = n % pow;
		pow /= 10;
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		pow;
	char	*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = ft_digit(n);
	pow = ft_power(10, digit - 1);
	if (n >= 0)
	{
		p = malloc(digit + 1);
		if (!p)
			return (NULL);
		p = ft_fil_s(p, n, pow, digit + 1);
	}
	else
	{
		p = malloc(digit + 2);
		if (!p)
			return (NULL);
		p[0] = '-';
		n = n * -1;
		p = ft_fil_s(p + 1, n, pow, digit + 1) - 1;
	}
	return (p);
}
