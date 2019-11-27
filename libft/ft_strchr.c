/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:23:35 by soyster           #+#    #+#             */
/*   Updated: 2019/04/17 21:26:48 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*sh;

	ch = (char)c;
	sh = (char*)s;
	while (*sh)
	{
		if (*sh == ch)
			return ((char*)sh);
		sh++;
	}
	if (ch == '\0')
		return ((char*)sh);
	return (0);
}
