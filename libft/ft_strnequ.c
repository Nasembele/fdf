/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:08:22 by soyster           #+#    #+#             */
/*   Updated: 2019/04/19 20:51:21 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	if (s1 && s2 && n > 0)
	{
		while (s1[i] != '\0' && i < n - 1 && s1[i] == s2[i])
			i++;
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (res == 0)
			return (1);
		else
			return (0);
	}
	return (1);
}
