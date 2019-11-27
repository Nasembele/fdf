/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:49:01 by soyster           #+#    #+#             */
/*   Updated: 2019/05/01 15:31:15 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char const *s, size_t l)
{
	if ((s[l - 1] == ' ' || s[l - 1] == '\n' ||
			s[l - 1] == '\t') && s[l - 1])
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	lnew;

	i = 0;
	j = 0;
	if (s)
	{
		l = ft_strlen(s);
		while (ft_isspace(s, l))
			l--;
		if (l == 0)
			return (ft_strnew(0));
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		lnew = l - i;
		if (!(result = ft_memalloc(lnew + 1)))
			return (0);
		while (j < lnew)
			result[j++] = s[i++];
		return (result);
	}
	return (0);
}
