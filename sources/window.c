/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/28 19:24:37 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(void *param)
{
	(void)param;
	exit(0);
}

static void	calculate_z(int x, int y, t_map *map)
{
	if (map->arr[y][x] > map->pos.max_z)
		map->pos.max_z = map->arr[y][x];
	else if (map->arr[y][x] < map->pos.min_z)
		map->pos.min_z = map->arr[y][x];
}

int			manage_paint(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			calculate_z(x, y, map);
			if (x < map->width - 1 && y < map->height - 1)
			{
				bresenham(x, y, RIGHT, &map);
				bresenham(x, y, DOWN, &map);
			}
			else if (x < map->width - 1)
				bresenham(x, y, RIGHT, &map);
			else if (y < map->height - 1)
				bresenham(x, y, DOWN, &map);
		}
	}
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.win, map->mlx.img, 0, 0);
	ft_memset(map->mlx.data, 000000, HEIGHT * WIDTH * 4);
	return (0);
}

int			mouse_event(int keycode, int x, int y, t_map *map)
{
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	manage_paint(map);
	return (0);
}

int			create_window(t_map *map)
{
	map->pos.center_x = map->width / 2;
	map->pos.center_y = map->height / 2;
	if (!(map->mlx.ptr = mlx_init()))
		return (1);
	map->mlx.win = mlx_new_window(map->mlx.ptr, WIDTH, HEIGHT, "FDF");
	map->mlx.img = mlx_new_image(map->mlx.ptr, WIDTH, HEIGHT);
	map->mlx.data = mlx_get_data_addr(map->mlx.img, &(map->mlx.bpp), \
									&(map->mlx.size_line), &(map->mlx.endian));
	ft_memset(map->mlx.data, 000000, HEIGHT * WIDTH * 4);
	manage_paint(map);
	mlx_hook(map->mlx.win, 17, 0, close_window, map);
	mlx_hook(map->mlx.win, 2, 0, keyboard_event, map);
	mlx_hook(map->mlx.win, 4, 0, mouse_event, map);
	mlx_loop(map->mlx.ptr);
	return (0);
}
