/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:14:33 by soyster           #+#    #+#             */
/*   Updated: 2019/04/23 21:43:02 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	index;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	if (size <= lendst)
		lensrc = lensrc + size;
	else
		lensrc = lensrc + lendst;
	index = 0;
	while (src[index] != '\0' && lendst < size - 1)
	{
		dst[lendst] = src[index];
		lendst++;
		index++;
	}
	dst[lendst] = '\0';
	return (lensrc);
}
