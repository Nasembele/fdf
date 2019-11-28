/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/28 18:17:38 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_height(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (i);
}

int			ft_error(void)
{
	ft_putstr("error\n");
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	int		height;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (ft_error());
		height = ft_height(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if (!(map = ft_validation(fd, height)))
			return (ft_error());
		create_window(map);
		close(fd);
	}
	else
		write(1, "usage: ./fdf target_filename\n", 29);
	return (0);
}
