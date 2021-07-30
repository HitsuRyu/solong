/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:34 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:03:34 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_items(t_items *items)
{
	items->c = 0;
	items->p = 0;
	items->e = 0;
}

void	check_items(char **map, t_items *items, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == '0' \
	|| map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
	{
		if (map[i][j] == 'C')
			items->c++;
		if (map[i][j] == 'P')
			items->p++;
		if (map[i][j] == 'E')
			items->e++;
	}
	else
		map_cleaner(3, map);
}

void	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		if (i == 0 || map[i + 1] == NULL)
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] != '1')
					map_cleaner(1, map);
				j++;
			}
		}
		else
		{
			if (*map[i] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				map_cleaner(1, map);
		}
		i++;
	}
}

void	check_len(char **map)
{
	size_t	len;

	len = ft_strlen(map[0]);
	while (*map)
	{
		if (ft_strlen(*map) != len)
			map_cleaner(2, map);
		map++;
	}
}

void	check_content(char **map)
{
	t_items	items;
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_items(&items);
	while (map[i])
	{
		while (map[i][j])
		{
			check_items(map, &items, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (items.c < 1 || items.p != 1 || items.e < 1)
		map_cleaner(3, map);
}
