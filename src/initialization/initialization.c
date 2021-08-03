/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:01:16 by cdahlia           #+#    #+#             */
/*   Updated: 2021/08/03 20:02:24 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		map_cleaner(4, info->map);
	get_sprite_info(info);
	get_window_info(info);
	get_player_info(info);
	draw_map(info);
}

void	get_sprite_info(t_info *info)
{
	info->sprite.wall = mlx_xpm_file_to_image(info->mlx, \
	"./src/initialization/xpm/wall.xpm", \
	&info->sprite.width, &info->sprite.height);
	info->sprite.coin = mlx_xpm_file_to_image(info->mlx, \
	"./src/initialization/xpm/coin.xpm", \
	&info->sprite.width, &info->sprite.height);
	info->sprite.player = mlx_xpm_file_to_image(info->mlx, \
	"./src/initialization/xpm/player.xpm", \
	&info->sprite.width, &info->sprite.height);
	info->sprite.empty = mlx_xpm_file_to_image(info->mlx, \
	"./src/initialization/xpm/empty.xpm", \
	&info->sprite.width, &info->sprite.height);
	info->sprite.exit = mlx_xpm_file_to_image(info->mlx, \
	"./src/initialization/xpm/exit.xpm", \
	&info->sprite.width, &info->sprite.height);
	if (!info->sprite.wall || !info->sprite.coin || \
	!info->sprite.player || !info->sprite.empty || \
	!info->sprite.exit)
		map_cleaner(4, info->map);
}

void	get_window_info(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
		i++;
	info->window.width = 50 * ft_strlen(info->map[0]);
	info->window.height = 50 * i + 50;
	mlx_get_screen_size(info->mlx, &info->window.screen_width, \
	&info->window.screen_height);
	if (info->window.width > info->window.screen_width || \
	info->window.height > info->window.screen_height)
		map_cleaner(4, info->map);
	info->window.win = mlx_new_window(info->mlx, info->window.width, \
	info->window.height, "./so_long");
	if (!info->window.win)
		map_cleaner(4, info->map);
}

void	get_player_info(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	info->player.moves = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'P')
			{
				info->player.x_pos = j;
				info->player.y_pos = i;
				info->map[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}
