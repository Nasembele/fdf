/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:11:59 by soyster           #+#    #+#             */
/*   Updated: 2019/04/28 22:48:40 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (size + 1 == 0)
		return (0);
	str = ft_memalloc(size + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return ((char*)str);
}
