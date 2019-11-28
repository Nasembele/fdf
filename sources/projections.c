/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/28 18:12:04 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			rotation_x(int *x, int *y, int *z, t_map **map)
{
	int				previous_y;

	previous_y = *y;
	*y = cos((*map)->pos.alpha) * previous_y + sin((*map)->pos.alpha) * *z;
	*z = -sin((*map)->pos.alpha) * previous_y + cos((*map)->pos.alpha) * *z;
}

static void			rotation_y(int *x, int *y, int *z, t_map **map)
{
	int				previous_x;

	previous_x = *x;
	*x = previous_x * cos((*map)->pos.beta) + *z * sin((*map)->pos.beta);
	*z = -previous_x * sin((*map)->pos.beta) + *z * cos((*map)->pos.beta);
}

static void			rotation_z(int *x, int *y, int *z, t_map **map)
{
	int				previous_x;
	int				previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = cos((*map)->pos.gamma) * previous_x \
		- sin((*map)->pos.gamma) * previous_y;
	*y = sin((*map)->pos.gamma) * previous_x \
		+ cos((*map)->pos.gamma) * previous_y;
}

void				iso(int *x, int *y, int *z, t_map **map)
{
	int				previous_x;
	int				previous_y;
	int				previous_z;

	if (*z != 0)
		*z += (*map)->pos.scroll;
	*z *= (*map)->pos.zoom;
	rotation_x(0, y, z, map);
	rotation_y(x, 0, z, map);
	rotation_z(x, y, 0, map);
	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = (previous_x - previous_y) * cos(0.46373398);
	*y = -previous_z + (previous_x + previous_y) * sin(0.46373398);
}
