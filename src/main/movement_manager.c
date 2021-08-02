/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:30 by cdahlia           #+#    #+#             */
/*   Updated: 2021/08/02 16:09:17 by cdahlia          ###   ########.fr       */
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

void	print_moves(t_info *info)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_itoa(info->player.moves);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	while (info->map[0][j])
	{
		mlx_put_image_to_window(info->mlx, info->window.win, \
		info->sprite.empty, j * 50, info->window.height - 50);
		j++;
	}
	mlx_string_put(info->mlx, info->window.win, info->window.width / 2, \
	(info->window.height - 25), 16711680, tmp);
	free(tmp);
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
	print_moves(info);
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
	print_moves(info);
}
