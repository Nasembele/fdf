/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:38:18 by soyster           #+#    #+#             */
/*   Updated: 2019/04/28 22:42:38 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str1;
	char	*str2;
	char	*result;

	if (s)
	{
		if (ft_strlen(s) + 1 == 0)
			return (0);
		result = (char*)ft_memalloc(ft_strlen(s) + 1);
		if (result == 0 || f == 0)
			return (0);
		str1 = (char*)s;
		str2 = result;
		while (*str1)
		{
			*str2 = f(*str1);
			str1++;
			str2++;
		}
		return (result);
	}
	return (0);
}
