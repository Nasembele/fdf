/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:21:59 by soyster           #+#    #+#             */
/*   Updated: 2019/05/01 16:06:10 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*strdst;
	const unsigned char	*strsrc;
	size_t				i;

	if (len == 0 && !src)
		return (0);
	strdst = (unsigned char*)dst;
	strsrc = (const unsigned char*)src;
	i = 0;
	if (strsrc < strdst)
		while (++i <= len)
			strdst[len - i] = strsrc[len - i];
	else
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	return ((void*)strdst);
}
