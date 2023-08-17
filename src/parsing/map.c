/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:29:25 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/14 16:45:09 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_valid(char *map, t_lst *list)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == 'N')
			n += 1;
		else if (map[i] == 'S')
			n += 1;
		else if (map[i] == 'E')
			n += 1;
		else if (map[i] == 'W')
			n += 1;
		else if (map[i] == '\n' && map[i + 1] == '\n')
			ft_error("TWO NEWLINES !\n");
		else if (map[i] != '0' && map[i] != '1'
			&& map[i] != ' ' && map[i] != '\n')
			ft_error("THERE IS SOMETHING OTHER THAN (1 0 N S E W) !\n");
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
			list->orie = map[i];
	}
	if (n != 1)
		ft_error("THE MAP IS NOT VALID (N S E W) !\n");
}

void	space_join(char **map_test, int i)
{
	int		max;
	int		len;
	char	*str;

	max = ft_strlen(map_test[0]);
	while (map_test[++i])
	{
		len = ft_strlen(map_test[i]);
		if (max < len)
			max = len;
	}
	i = -1;
	while (map_test[++i])
	{
		len = ft_strlen(map_test[i]);
		if (max > len)
		{
			str = malloc((max - len) + 1);
			ft_memset(str, ' ', max - len);
			str[max - len] = '\0';
			map_test[i] = ft_strjoin(map_test[i], str);
			free(str);
		}
	}
}

void	map_closed(char **map_test, int x, int y, int len)
{
	while (map_test[len])
		len++;
	while (map_test[++y])
	{
		x = -1;
		while (map_test[y][++x])
		{
			if ((x == 0 && map_test[y][x] != '1' && map_test[y][x] != ' ')
				|| (y == 0 && map_test[y][x] != '1' && map_test[y][x] != ' ')
				|| (y == len - 1 && map_test[y][x] != '1'
				&& map_test[y][x] != ' '))
				ft_error("THE MAP IS NOT CLOSED BY (1)!\n");
			else if ((map_test[y][x] == '0') || (map_test[y][x] == 'N')
				|| (map_test[y][x] == 'S') || (map_test[y][x] == 'E')
				|| (map_test[y][x] == 'W'))
			{
				if ((map_test[y][x + 1] == '\0') || (map_test[y][x - 1] == ' ')
					|| (map_test[y][x + 1] == ' ')
					|| (map_test[y + 1][x] == ' ')
					|| (map_test[y - 1][x] == ' '))
					ft_error("THE MAP IS NOT CLOSED BY (1)!\n");
			}
		}
	}
}

void	ft_map(t_lst *list, char *str_map)
{
	char	**map;
	int		i;

	i = -1;
	check_map_valid(str_map, list);
	map = ft_split(str_map, '\n');
	space_join(map, -1);
	map_closed(map, -1, -1, 0);
	list->map = map;
}
