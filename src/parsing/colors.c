/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:41:06 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/08 11:22:01 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cut_color_help(char **str_spl, int *nb, int i)
{
	int		len;
	int		j;
	char	*str;

	j = 0;
	len = 0;
	str = ft_strtrim(str_spl[i], " ");
	while (str[j] == '0')
		j++;
	len = j;
	while (str[len])
	{
		if (str[len] < '0' || str[len] > '9')
			ft_error("THE COLOR IS NOT NUMBER !\n");
		len++;
	}
	len -= j;
	*nb = ft_atoi(str + j);
	if (!str[0] || len > 3 || *nb > 255 || *nb < 0)
		ft_error("THE COLOR NUMBER GREATER THAN THE LIMIT !\n");
	free(str);
}

void	ft_cut_color(t_lst *list, char **str_spl, char x)
{
	int	nb;
	int	i;

	i = -1;
	nb = 0;
	while (++i < 3)
	{
		cut_color_help(str_spl, &nb, i);
		if (x == 'f')
			list->f[i] = nb;
		else
			list->c[i] = nb;
	}
}

void	foort_ceiling_help(t_lst *list, int intervale, char *str, char x)
{
	char	**str_spl;
	int		i;

	i = 0;
	if (intervale != 2)
		ft_error("THE FLOOR COLOR IS NOT VALID (intervale{,})\n");
	str_spl = ft_split(str, ',');
	i = 0;
	while (str_spl[i])
		i++;
	if (i != 3)
		ft_error("COLOR IS NOT VALID\n");
	ft_cut_color(list, str_spl, x);
	i = -1;
	free(str_spl);
}

void	foort_ceiling(t_lst *list, char **tmp, char x, int i)
{
	char	*str;
	int		intervale;

	intervale = 0;
	(*tmp) += 2;
	while ((*tmp)[i] != '\n')
		i++;
	str = malloc(i + 1);
	if (x == 'f')
		list->f = malloc((3) * sizeof(int));
	else
		list->c = malloc((3) * sizeof(int));
	i = 0;
	while (**tmp != '\n')
	{
		str[i++] = **tmp;
		if (**tmp == ',')
			intervale++;
		(*tmp)++;
	}
	str[i] = '\0';
	foort_ceiling_help(list, intervale, str, x);
	free(str);
}
