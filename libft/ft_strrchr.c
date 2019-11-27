/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:44:35 by soyster           #+#    #+#             */
/*   Updated: 2019/04/23 04:26:16 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			len;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != ch)
		len--;
	if (s[len] == ch)
		return ((char*)&s[len]);
	else
		return (0);
}
