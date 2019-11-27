/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:40:02 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/18 00:05:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			add_start_pos(int *x0, int *y0, int key, t_map **map)
{
	if (key == 0)
	{
		*x0 += (*map)->pos.start_x;
		*y0 += (*map)->pos.start_y;
	}
	else if (key == 1)
	{
		(*map)->line.x1 += (*map)->pos.start_x;
		(*map)->line.y1 += (*map)->pos.start_y;
	}
}

static void			drctn_processing(int x, int y, int direction, t_map **map)
{
	if (direction == 2)
	{
		(*map)->line.x1 = -((*map)->pos.center_x - (x + 1)) * (*map)->pos.zoom;
		(*map)->line.y1 = -((*map)->pos.center_y - y) * (*map)->pos.zoom;
		(*map)->line.z1 = (*map)->arr[y][x + 1];
		iso(&(*map)->line.x1, &(*map)->line.y1, &(*map)->line.z1, map);
	}
	else
	{
		(*map)->line.x1 = -((*map)->pos.center_x - x) * (*map)->pos.zoom;
		(*map)->line.y1 = -((*map)->pos.center_y - (y + 1)) * (*map)->pos.zoom;
		(*map)->line.z1 = (*map)->arr[y + 1][x];
		iso(&(*map)->line.x1, &(*map)->line.y1, &(*map)->line.z1, map);
	}
}

static void			option_1(int x0, int y0, t_map **map)
{
	while (x0 != (*map)->line.x1 || y0 != (*map)->line.y1)
	{
		(*map)->line.f += (*map)->line.a * (*map)->line.key_a;
		if ((*map)->line.f > 0)
		{
			(*map)->line.f -= (*map)->line.b * (*map)->line.key_b;
			y0 += (*map)->line.key_a;
		}
		x0 -= (*map)->line.key_b;
		put_pixel(map, x0, y0, (*map)->color);
	}
}

static void			option_2(int x0, int y0, t_map **map)
{
	while (x0 != (*map)->line.x1 || y0 != (*map)->line.y1)
	{
		(*map)->line.f += (*map)->line.b * (*map)->line.key_b;
		if ((*map)->line.f > 0)
		{
			(*map)->line.f -= (*map)->line.a * (*map)->line.key_a;
			x0 -= (*map)->line.key_b;
		}
		y0 += (*map)->line.key_a;
		put_pixel(map, x0, y0, (*map)->color);
	}
}

void				bresenham(int x, int y, int direction, t_map **map)
{
	(*map)->line.x0 = -((*map)->pos.center_x - x) * (*map)->pos.zoom;
	(*map)->line.y0 = -((*map)->pos.center_y - y) * (*map)->pos.zoom;
	(*map)->line.z0 = (*map)->arr[y][x];
	iso(&(*map)->line.x0, &(*map)->line.y0, &(*map)->line.z0, map);
	add_start_pos(&(*map)->line.x0, &(*map)->line.y0, 0, map);
	drctn_processing(x, y, direction, map);
	add_start_pos(0, 0, 1, map);
	(*map)->line.a = (*map)->line.y1 - (*map)->line.y0;
	(*map)->line.b = (*map)->line.x0 - (*map)->line.x1;
	(*map)->line.key_a = (*map)->line.a < 0 ? -1 : 1;
	(*map)->line.key_b = (*map)->line.b < 0 ? -1 : 1;
	abs((*map)->line.a) < abs((*map)->line.b) \
	? option_1((*map)->line.x0, (*map)->line.y0, map) \
	: option_2((*map)->line.x0, (*map)->line.y0, map);
}
