#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_info
{
	void *mlx;
	void *win;
	void *img;
	int window_width;
	int window_height;
	int x;
	int y;
}               t_info;

int key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
	{
		if (info->y - 30 <= 0)
		{
			mlx_clear_window(info->mlx, info->win);
			info->y = 0;
			mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
			return (-1);
		}
		write(1, "move up\n", 9);
		mlx_clear_window(info->mlx, info->win);
		info->y -= 30;
		mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
	}
	if (keycode == 1)
	{
		if (info->y + 30 >= info->window_height)
		{
			mlx_clear_window(info->mlx, info->win);
			info->y = info->window_height;
			mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
			return (-1);
		}
		write(1, "move down\n", 11);
		mlx_clear_window(info->mlx, info->win);
		info->y += 30;
		mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
	}
	if (keycode == 0)
	{
		if (info->x - 30 <= 0)
		{
			mlx_clear_window(info->mlx, info->win);
			info->x = 0;
			mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
			return (-1);
		}
		write(1, "move left\n", 11);
		mlx_clear_window(info->mlx, info->win);
		info->x -= 30;
		mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
	}
	if (keycode == 2)
	{
		if (info->x + 30 >= info->window_width)
		{
			mlx_clear_window(info->mlx, info->win);
			info->x = info->window_width;
			mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
			return (-1);
		}
		write(1, "move right\n", 12);
		mlx_clear_window(info->mlx, info->win);
		info->x += 30;
		mlx_put_image_to_window(info->mlx, info->win, info->img, info->x, info->y);
	}
	return (0);
}

int main()
{
	t_info info;
	int h;
	int w;
	info.x = 0;
	info.y = 0;
	info.window_width = 640;
	info.window_height = 480;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.window_width, info.window_height, "so_long");
	info.img = mlx_xpm_file_to_image(info.mlx, "mario.xpm", &w, &h);
	mlx_put_image_to_window(info.mlx, info.win, info.img, info.x, info.y);
	mlx_key_hook(info.win, key_hook, &info);
	mlx_loop(info.mlx);
}