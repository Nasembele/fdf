/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/22 21:39:53 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			zoom(t_map *map, int keycode)
{
	if (keycode == PLUS)
		map->pos.zoom += 2;
	else if (keycode == MINUS && (map->pos.zoom != 2))
		map->pos.zoom -= 2;
}

static void			recolor(t_map *map, int keycode)
{
	if (keycode == 83)
		map->color = RED;
	else if (keycode == 84)
		map->color = GREEN;
	else if (keycode == 85)
		map->color = BLUE;
	else if (keycode == 86)
		map->color = WHITE;
	else if (keycode == 87)
		map->color = PINK;
	else if (keycode == 88)
		map->color = PURPLE;
	else if (keycode == 89)
		map->gradient_flag = 1;
	else if (keycode == 91)
		map->gradient_flag = 2;
	else if (keycode == 92)
		map->gradient_flag = 3;
}

static void			move(t_map *map, int keycode)
{
	if (keycode == 0)
		map-> pos.start_x -= 4;
	if (keycode == 2)
		map->pos.start_x += 4;
	if (keycode == 1)
		map->pos.start_y += 4;
	if (keycode == 13)
		map->pos.start_y -= 4;
}

static void			turn(t_map *map, int keycode)
{
	if (keycode == 18)
		map->pos.alpha -= 0.05;
	if (keycode == 19)
		map->pos.alpha += 0.05;
	if (keycode == 20)
		map->pos.beta -= 0.05;
	if (keycode == 21)
		map->pos.beta += 0.05;
	if (keycode == 23)
		map->pos.gamma -= 0.05;
	if (keycode == 22)
		map->pos.gamma += 0.05;
}

int					keyboard_event(int keycode, t_map *map)
{
	if (keycode == EXIT)
		exit(0);
	else
	{
		if (keycode == PLUS || keycode == MINUS)
			zoom(map, keycode);
		if (keycode >= 83 && keycode <= 88)
			recolor(map, keycode);
		if ((keycode >= 0 && keycode <= 2) || keycode == 13)
			move(map, keycode);
		if (keycode >= 18 && keycode <= 23)
			turn(map, keycode);
		if (keycode == 49)
		{
			map->pos.alpha = 0;
			map->pos.beta = 0;
			map->pos.gamma = 0;
		}
		mlx_clear_window(map->mlx.ptr, map->mlx.win);
		manage_paint(map);
	}
	return (0);
}
