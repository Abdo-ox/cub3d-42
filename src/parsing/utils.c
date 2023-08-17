/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:45:46 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/17 10:05:29 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init(t_lst *list)
{
	list->north = malloc(sizeof(t_textures));
	list->south = malloc(sizeof(t_textures));
	list->west = malloc(sizeof(t_textures));
	list->east = malloc(sizeof(t_textures));
	list->sx = 0;
	list->sy = 0;
	list->map = NULL;
	list->no = NULL;
	list->so = NULL;
	list->we = NULL;
	list->ea = NULL;
	list->c = 0;
	list->f = 0;
	list->old_p = -1;
}

int	check_name_file(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (1);
	if (str[len - 1] == 'b' && str[len - 2] == 'u' && str[len - 3] == 'c'
		&& str[len - 4] == '.' && str[len - 5] && str[len - 5] != '/')
		return (0);
	return (1);
}

char	*read_line(char *name_file, int fd)
{
	int		i;
	char	*p;
	char	*str;
	char	*map;
	char	buf[7];

	p = NULL;
	fd = open(name_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error: OPEN FILE\n");
	p = ft_strdup("");
	i = 0;
	i = read(fd, buf, 6);
	if (!i)
		free(p);
	while (i)
	{
		buf[i] = '\0';
		str = ft_strdup(buf);
		map = ft_strjoin(p, str);
		i = read(fd, buf, 6);
		free(str);
		p = map;
	}
	return (map);
}

void	fill_in_struct(t_lst *list, char *tmp)
{
	ft_init(list);
	while (*tmp)
	{
		if (*tmp == 'N' && tmp[1] == 'O')
			north(list, &tmp);
		else if (*tmp == 'S' && tmp[1] == 'O')
			south(list, &tmp);
		else if (*tmp == 'W' && tmp[1] == 'E')
			west(list, &tmp);
		else if (*tmp == 'E' && tmp[1] == 'A')
			east(list, &tmp);
		else if (*tmp == 'F' && tmp[1] && tmp[1] == ' ' && !list->f)
			foort_ceiling(list, &tmp, 'f', 0);
		else if (*tmp == 'C' && tmp[1] && tmp[1] == ' ' && !list->c)
			foort_ceiling(list, &tmp, 'c', 0);
		else if ((*tmp == ' ' || *tmp == '1') && list->no && list->so
			&& list->we && list->ea && list->f && list->c)
		{
			ft_map(list, tmp);
			break ;
		}
		else if (*tmp != '\n')
			ft_error("Error in the map !\n");
		tmp++;
	}
}
