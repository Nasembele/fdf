/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 04:43:36 by soyster           #+#    #+#             */
/*   Updated: 2019/07/10 21:44:31 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_realloc(char *buff, char **store)
{
	char		*tmp_line;

	if (!(*store))
		*store = ft_strnew(0);
	tmp_line = ft_strjoin(*store, buff);
	free(*store);
	*store = tmp_line;
}

static	int		ft_line(char **store, char **line)
{
	char		*help;
	size_t		pos;

	if (*store && !(ft_strchr(*store, '\n')))
	{
		*line = ft_strdup(*store);
		ft_strdel(&(*store));
		return (1);
	}
	pos = (ft_strchr(*store, '\n')) - *store;
	*line = ft_strsub(*store, 0, pos);
	if (!(*line))
		return (-1);
	help = ft_strsub(*store, pos + 1, ft_strlen(*store) - (pos + 1));
	if (!(*store))
		return (-1);
	free(*store);
	*store = help;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*store[10240];
	size_t		rd;

	rd = 0;
	if (fd < 0 || !line || read(fd, buff, 0))
		return (-1);
	if (!store[fd] || !(ft_strchr(store[fd], '\n')))
	{
		while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[rd] = '\0';
			ft_realloc(buff, &(store[fd]));
			if (ft_strchr(store[fd], '\n') != NULL)
				break ;
		}
	}
	if (rd == 0 && !store[fd])
	{
		*line = NULL;
		return (0);
	}
	return (ft_line(&store[fd], &(*line)));
}
