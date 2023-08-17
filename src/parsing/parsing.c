/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:28:34 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/17 10:46:03 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	rgb(int *i)
{
	return ((i[0] * 256 * 256) + (i[1] * 256) + i[2]);
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	exit(1);
}

t_lst	*list(int ac, char **env)
{
	t_lst	*list;
	char	*map;
	char	*tmp;

	list = malloc(sizeof(t_lst));
	if (ac != 2 || check_name_file(env[1]))
		ft_error("Error: NAME FILE\n");
	map = read_line(env[1], 0);
	tmp = map;
	fill_in_struct(list, tmp);
	if (!list->map)
		ft_error("Error: THE MAP EMPTY !\n");
	while (list->map[list->sy])
		list->sy++;
	list->sx = ft_strlen(list->map[0]);
	list->cr = rgb(list->c);
	list->fr = rgb(list->f);
	return (free(map), list);
}
