/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:32 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 20:08:06 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 0x71)
	{
		mlx_destroy_window(info->mlx, info->window.win);
		map_cleaner(0, info->map);
	}
	if ((keycode == 0x61) || (keycode == 0x73) ||(keycode == 0x64) || (keycode == 0x77))
		movement_manager(info, keycode);
	return (0);
}

int	window_hook(t_info *info)
{
	mlx_destroy_window(info->mlx, info->window.win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
	{
		write(1, "Error\nNo map specified.\n", 24);
		exit(-1);
	}
	info.map = map_parser(argv[1]);
	initialization(&info);
	mlx_key_hook(info.window.win, key_hook, &info);
	// mlx_hook(info.window.win, 17, 1L << 0, key_hook, &info);
	mlx_hook(info.window.win, 17, 1L << 5, window_hook, &info);
	mlx_loop(info.mlx);
}
