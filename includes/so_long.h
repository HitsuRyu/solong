/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:05:36 by cdahlia           #+#    #+#             */
/*   Updated: 2021/08/02 14:16:21 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sprite
{
	int		width;
	int		height;
	void	*wall;
	void	*empty;
	void	*coin;
	void	*player;
	void	*exit;
}				t_sprite;

typedef struct s_window
{
	void	*win;
	int		width;
	int		height;
	int		screen_width;
	int		screen_height;
}				t_window;

typedef struct s_player
{
	int	x_pos;
	int	y_pos;
	int	moves;
}				t_player;

typedef struct s_info
{
	void		*mlx;
	char		**map;
	int			coins_left;
	t_sprite	sprite;
	t_window	window;
	t_player	player;
}				t_info;

typedef struct s_items
{
	int	c;
	int	p;
	int	e;
}				t_items;

int		key_hook(int keycode, t_info *info);
void	movement_manager(t_info *info, int keycode);
void	move_player(t_info *info, int x_offset, int y_offset);
void	draw_new_pos(t_info *info, int x_offset, int y_offset);
void	draw_new_pos_coin(t_info *info, int x_offset, int y_offset);
char	**map_parser(char *filename);
void	map_cleaner(int errno, char **map);
void	check_walls(char **map);
void	check_len(char **map);
void	check_content(char **map);
void	check_items(char **map, t_items *items, int i, int j);
void	init_items(t_items *items);
void	initialization(t_info *info);
void	get_sprite_info(t_info *info);
void	get_window_info(t_info *info);
void	get_player_info(t_info *info);
void	draw_map(t_info *info);
void	item_drawer(t_info *info, int i, int j);

#endif
