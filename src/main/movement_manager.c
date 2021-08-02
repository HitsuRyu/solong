/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:30 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/31 12:19:45 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_manager(t_info *info, int keycode)
{
	if (keycode == 1 && info->map[info->player.y_pos \
	+ 1][info->player.x_pos] != '1')
		move_player(info, 0, 1);
	if (keycode == 13 && info->map[info->player.y_pos \
	- 1][info->player.x_pos] != '1')
		move_player(info, 0, -1);
	if (keycode == 0 && info->map[info->player.y_pos][info->player.x_pos \
	- 1] != '1')
		move_player(info, -1, 0);
	if (keycode == 2 && info->map[info->player.y_pos][info->player.x_pos \
	+ 1] != '1')
		move_player(info, 1, 0);
}

void	move_player(t_info *info, int x_offset, int y_offset)
{
	if (info->map[info->player.y_pos + y_offset][info->player.x_pos \
	+ x_offset] == '0')
	{
		draw_new_pos(info, x_offset, y_offset);
	}
	else if (info->map[info->player.y_pos + y_offset][info->player.x_pos \
	+ x_offset] == 'C')
	{
		draw_new_pos_coin(info, x_offset, y_offset);
	}
	else
	{
		if (info->coins_left == 0)
			map_cleaner(0, info->map);
	}
}

void	draw_new_pos(t_info *info, int x_offset, int y_offset)
{
	mlx_put_image_to_window(info->mlx, info->window.win, \
	info->sprite.empty, info->player.x_pos * 50, info->player.y_pos * 50);
	info->player.x_pos += x_offset;
	info->player.y_pos += y_offset;
	mlx_put_image_to_window(info->mlx, info->window.win, \
	info->sprite.player, info->player.x_pos * 50, info->player.y_pos * 50);
	info->player.moves++;
	ft_putnbr_fd(info->player.moves, 1);
	write(1, "\n", 1);
}

void	draw_new_pos_coin(t_info *info, int x_offset, int y_offset)
{
	mlx_put_image_to_window(info->mlx, info->window.win, \
	info->sprite.empty, info->player.x_pos * 50, info->player.y_pos * 50);
	info->player.x_pos += x_offset;
	info->player.y_pos += y_offset;
	mlx_put_image_to_window(info->mlx, info->window.win, \
	info->sprite.empty, info->player.x_pos * 50, info->player.y_pos * 50);
	mlx_put_image_to_window(info->mlx, info->window.win, \
	info->sprite.player, info->player.x_pos * 50, info->player.y_pos * 50);
	info->coins_left--;
	info->map[info->player.y_pos][info->player.x_pos] = '0';
	info->player.moves++;
	ft_putnbr_fd(info->player.moves, 1);
	write(1, "\n", 1);
}
