/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:45:31 by ajari             #+#    #+#             */
/*   Updated: 2023/06/17 10:42:41 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_angle(double t, double add, int i)
{
	while (--i)
	{
		t -= add;
		(t < 0) && (t = 2 * PI);
	}
	return (t);
}

void	my_mlxput_pixel(t_lst m, int x, int y, size_t color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WI || y >= HI)
		return ;
	offset = y * m.im.ln_len + x * (m.im.b_pxl / 8);
	*((unsigned int *)(m.im.ad + offset)) = color;
}
