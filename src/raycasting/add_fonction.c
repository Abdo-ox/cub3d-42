/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:25:19 by ajari             #+#    #+#             */
/*   Updated: 2023/06/17 10:52:51 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawln(t_lst m, t_ps p1, t_ps p2, int color)
{
	while (p1.y < p2.y){
		if (p1.x > 200 || p1.y > 200)
			my_mlxput_pixel(m, p1.x, p1.y, color);
		p1.y++;
	}
}
