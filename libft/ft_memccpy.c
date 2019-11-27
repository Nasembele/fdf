/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:51:39 by soyster           #+#    #+#             */
/*   Updated: 2019/04/15 17:59:47 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;
	unsigned char		sym;
	size_t				i;

	str1 = (unsigned char*)dst;
	str2 = (const unsigned char*)src;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == sym)
			return ((void*)(str1 + i + 1));
		i++;
	}
	return (0);
}
