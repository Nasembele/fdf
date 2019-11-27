/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:51:06 by soyster           #+#    #+#             */
/*   Updated: 2019/04/28 22:46:02 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str1;
	char			*str2;
	char			*result;
	unsigned int	i;

	if (s)
	{
		if (ft_strlen(s) + 1 == 0 || f == 0)
			return (0);
		if (!(result = (char*)ft_memalloc(ft_strlen(s) + 1)))
			return (0);
		str1 = (char*)s;
		str2 = result;
		i = 0;
		while (str1[i])
		{
			str2[i] = f(i, str1[i]);
			i++;
		}
		return (str2);
	}
	return (0);
}
