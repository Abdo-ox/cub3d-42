/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:36:20 by ajari             #+#    #+#             */
/*   Updated: 2023/06/17 10:57:39 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

double cord_horizo(t_lst m, double *x, double *y)
{
	double dx;
	double dy;

	dy = -SQ;
	*y = ((int)(m.p.y / SQ)) * SQ;
	if (m.t > 0 && m.t < PI)
		*y += SQ;
	if (m.t > 0 && m.t < PI)
		dy = SQ;
	dx = fabs(dy / tan(m.t));
	*x = m.p.x + fabs((*y - m.p.y) / tan(m.t));
	if (m.t > PD && m.t < 3 * PD)
		*x = m.p.x - fabs((*y - m.p.y) / tan(m.t));
	if (m.t > PD && m.t < 3 * PD)
		dx *= -1;
	while (1)
	{
		if (check_wall(m, *x, *y, 1))
			break;
		*y += dy;
		*x += dx;
	}
	if (*y > m.sy * SQ)
		*y = (m.sy - 1) * SQ;
	if (*x > m.sx * SQ)
		*x = (m.sx - 1) * SQ;
	if (*x < 0)
		*x = 0;
	if (*y < 0)
		*y = 0;
	return (sqrt(pow(m.p.x - *x, 2) + pow(m.p.y - *y, 2)));
}

double cord_verti(t_lst m, double *x, double *y)
{
	double dx;
	double dy;

	dx = SQ;
	*x = ((int)(m.p.x / SQ)) * SQ;
	if (m.t < PD || m.t > 3 * PD)
		*x += SQ;
	if (m.t > PD && m.t < 3 * PD)
		dx = -SQ;
	dy = fabs(dx * tan(m.t));
	*y = m.p.y - fabs((*x - m.p.x) * tan(m.t));
	if (m.t > 0 && m.t < PI)
		*y = m.p.y + fabs((*x - m.p.x) * tan(m.t));
	if (m.t > PI)
		dy *= -1;
	while (1)
	{
		if (check_wall(m, *x, *y, 0))
			break;
		*y += dy;
		*x += dx;
	}
	if (*y > m.sy * SQ)
		*y = (m.sy - 1) * SQ;
	if (*x > m.sx * SQ)
		*x = (m.sx - 1) * SQ;
	if (*x < 0)
		*x = 0;
	if (*y < 0)
		*y = 0;
	return (sqrt(pow(m.p.x - *x, 2) + pow(m.p.y - *y, 2)));
}

void rays(t_lst m, double dh, double dv, double t)
{
	double h_x;
	double h_y;
	double v_x;
	double v_y;

	m.i = WI / 2;
	t = m.t;
	while (--m.i >= 0)
	{
		m.t -= (PI / 3) / WI;
		if (m.t < 0)
			(m.t = 2 * PI);
	}
	while (++m.i < WI)
	{
		dh = cord_horizo(m, &h_x, &h_y);
		dv = cord_verti(m, &v_x, &v_y);
		if (dh < dv)
			(dv = dh, v_x = h_x, v_y = h_y);
		dh = ceil(fabs((SQ * 320) / (dv * cos(fabs(m.t - t))))) * 2;
		drawln(m, (t_ps){m.i, 0}, (t_ps){m.i, fabs((HI - dh) / 2)}, m.cr);
		texters(m, dh, v_x, v_y);
		drawln(m, (t_ps){m.i, fabs((HI - dh) / 2 + dh)}, (t_ps){m.i, HI}, m.fr);
		m.t += (PI / 3) / WI;
		if (m.t > 2 * PI)
			m.t = 0;
	}
}
