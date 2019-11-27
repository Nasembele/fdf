/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:42:01 by soyster           #+#    #+#             */
/*   Updated: 2019/04/28 22:35:26 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 && s2)
	{
		if (ft_strlen(s1) + ft_strlen(s2) + 1 == 0)
			return (0);
		result = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (result == 0)
			return (0);
		result = ft_strcat(result, (char*)s1);
		result = ft_strcat(result, s2);
		return ((char*)result);
	}
	return (0);
}
