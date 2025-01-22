/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:31 by ajari             #+#    #+#             */
/*   Updated: 2023/06/17 10:48:18 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>
void	get_images(t_lst *m)
{
	m->north->img = mlx_xpm_file_to_image(m->mx, m->no, &m->north->w,
			&m->north->h);
	m->south->img = mlx_xpm_file_to_image(m->mx, m->so, &m->south->w,
			&m->south->h);
	m->west->img = mlx_xpm_file_to_image(m->mx, m->we, &m->west->w,
			&m->west->h);
	m->east->img = mlx_xpm_file_to_image(m->mx, m->ea, &m->east->w,
			&m->east->h);
	if (!m->north->img || !m->south->img || !m->west->img || !m->east->img)
		ft_error("Error: open images\n");
	m->north->im.ad = mlx_get_data_addr(m->north->img, &m->north->im.b_pxl,
			&m->north->im.ln_len, &m->north->im.edn);
	m->south->im.ad = mlx_get_data_addr(m->south->img, &m->south->im.b_pxl,
			&m->south->im.ln_len, &m->south->im.edn);
	m->west->im.ad = mlx_get_data_addr(m->west->img, &m->west->im.b_pxl,
			&m->west->im.ln_len, &m->west->im.edn);
	m->east->im.ad = mlx_get_data_addr(m->east->img, &m->east->im.b_pxl,
			&m->east->im.ln_len, &m->east->im.edn);
}

int	move_key(int k, t_lst *m)
{
	double	t;
	bool nothing;
	t = m->t;
	
	if (k == KEY_ESC)
		exit(0);
	//put_ply(*m, (t_ps){100, 100}, BLACK);
	//rays(*m, 0, 0, BLACK);
	var_angle(k, m);
	nothing = (ok(m, k) == KEY_DOWN) && (m->p.x -= cos(t) * S, m->p.y -= sin(t) * S);
	nothing = (ok(m, k) == KEY_UP) && (m->p.x += cos(t) * S, m->p.y += sin(t) * S);
	nothing = (ok(m, k) == 0) && (m->p.x -= cos(t + PD) * S, m->p.y -= sin(t + PD) * S);
	nothing = (ok(m, k) == 2) && (m->p.x += cos(t + PD) * S, m->p.y += sin(t + PD) * S);
	nothing = (ok(m, k) == KEY_W) && (m->p.x -= cos(t + PI) * S, m->p.y -= sin(t + PI) * S);
	nothing = (ok(m, k) == KEY_S) && (m->p.x += cos(t + PI) * S, m->p.y += sin(t + PI) * S);
	(void)nothing;
	rays(*m, 0, 0, BLUE);
	putwindow(*m, m->map, m->p.x, m->p.y);
	put_ply(*m, (t_ps){100, 100}, RED);
	mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
	return (0);
}

int	mousemove(int x, int y, t_lst *m)
{
	if (x < 0 || y < 0 || x > WI || y > HI)
		return (0);
	if (x < m->old_p)
		move_key(KEY_LEFT, m);
	else if (x > m->old_p)
		move_key(KEY_RIGHT, m);
	m->old_p = x;
	return (0);
}

int	destroy(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_lst	*m;

	m = list(ac, av);
	m->mx = mlx_init();
	get_images(m);
	m->wn = mlx_new_window(m->mx, WI, HI, "My Cub3D");
	m->im.p = mlx_new_image(m->mx, WI, HI);
	m->im.ad = mlx_get_data_addr(m->im.p, &m->im.b_pxl, &m->im.ln_len,
			&m->im.edn);
	get_psplayer(m, m->map);
	rays(*m, 0, 0, BLUE);
	putwindow(*m, m->map, m->p.x, m->p.y);
	mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
	put_ply(*m, (t_ps){100, 100}, RED);
	mlx_hook(m->wn, 2, 1L<<0, move_key, m);
	mlx_hook(m->wn, 6, 0, mousemove, m);
	mlx_hook(m->wn, 17, 0, destroy, NULL);
	mlx_loop(m->mx);
}
