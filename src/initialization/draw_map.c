/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:01:11 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:01:12 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	item_drawer(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		mlx_put_image_to_window(info->mlx, \
		info->window.win, info->sprite.wall, j * 50, i * 50);
	if (info->map[i][j] == 'C')
	{
		mlx_put_image_to_window(info->mlx, \
		info->window.win, info->sprite.coin, j * 50, i * 50);
		info->coins_left++;
	}
	if (info->map[i][j] == 'E')
		mlx_put_image_to_window(info->mlx, \
		info->window.win, info->sprite.exit, j * 50, i * 50);
}

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	info->coins_left = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			item_drawer(info, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
