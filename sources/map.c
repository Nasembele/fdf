/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/28 19:22:03 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			delete_map(t_map **map, int i)
{
	t_map	*node;

	if (!map || !*map)
		return (0);
	node = *map;
	ft_destroy_int_arr(node->arr, i);
	free(node);
	node = NULL;
	return (1);
}

t_map		*create_map(int height)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->arr = (int **)ft_memalloc(sizeof(int *) * height)))
	{
		free(map);
		return (NULL);
	}
	map->line.f = 0;
	map->pos.start_x = 630;
	map->pos.start_y = 700;
	map->pos.scroll = 0;
	map->pos.alpha = 0;
	map->pos.beta = 0;
	map->pos.gamma = 0;
	map->gradient_flag = 0;
	map->pos.zoom = 2;
	map->width = 0;
	map->height = height;
	map->color = PURPLE;
	return (map);
}

void		put_pixel(t_map **map, int x, int y, int color)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_memcpy(&(*map)->mlx.data[(x * 4) + (y * (*map)->mlx.size_line)], \
												&color, (size_t)(sizeof(int)));
}
