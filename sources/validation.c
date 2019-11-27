/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/27 16:28:13 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			free_ft(char *line, char **arr_str, int f1, int f2)
{
	if ((f1 == 0 || f1 == 2) && line != NULL)
		ft_strdel(&line);
	if (f1 == 1 || f1 == 2)
		ft_destroy_string_arr(arr_str);
	return (f2);
}

static int			cycle_read(int fd, char *line, char **arr_str, t_map *map)
{
	int				i;
	int				k;
	int				res;

	i = 1;
	while ((res = (get_next_line(fd, &line))))
	{
		k = -1;
		if (!(arr_str = ft_strsplit(line, ' ')) && (delete_map(&map, i - 1)))
			return (free_ft(line, NULL, 0, 1));
		if (map->width != ft_len_arr(arr_str) && (delete_map(&map, i - 1)))
			return (free_ft(line, arr_str, 2, 1));
		if (!(map->arr[i] = (int *)ft_memalloc(sizeof(int) * map->width)) \
			&& (delete_map(&map, i - 1)))
			return (free_ft(line, arr_str, 2, 1));
		while (++k != map->width)
			map->arr[i][k] = ft_getnbr(arr_str[k]);
		free_ft(line, arr_str, 2, 0);
		i++;
	}
	return (res == -1 ? -1 : 0);
}

static int			first_read(int fd, char *line, char **arr_str, t_map *map)
{
	int				k;

	k = -1;
	if (!get_next_line(fd, &line))
		return (-1);
	if (!(arr_str = ft_strsplit(line, ' ')))
		return (free_ft(line, NULL, 0, -1));
	map->width = ft_len_arr(arr_str);
	if (!(map->arr[0] = (int *)ft_memalloc(sizeof(int) * map->width)))
		return (free_ft(line, arr_str, 2, -1));
	while (++k != map->width)
		map->arr[0][k] = ft_getnbr(arr_str[k]);
	free_ft(line, arr_str, 2, 0);
	return (0);
}

t_map				*ft_validation(int fd, int height)
{
	int				res;
	t_map			*map;
	char			*line;
	char			**arr_str;

	if (!(map = create_map(height)))
		return (NULL);
	map->pos.min_z = 0;
	map->pos.max_z = 0;
	if ((res = first_read(fd, line, arr_str, map) == -1))
	{
		delete_map(&map, -1);
		return (NULL);
	}
	res = cycle_read(fd, line, arr_str, map);
	return (res == 0 ? map : NULL);
}