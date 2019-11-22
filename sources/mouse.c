/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/22 21:37:28 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void			scrolling(int keycode, t_map *map)
{
	if (keycode == 4)
		map->pos.scroll -= 3;
	if (keycode == 5)
		map->pos.scroll += 3;
}

int						mouse_event(int keycode, int x, int y, t_map *map)
{
	if (keycode == 2)
		map->sidebar_flag = map->sidebar_flag == 0 ? 1 : 0;
	if (keycode == 4 || keycode == 5)
		scrolling(keycode, map);
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	manage_paint(map);
	return (0);
}