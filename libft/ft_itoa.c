/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 23:37:31 by soyster           #+#    #+#             */
/*   Updated: 2019/04/30 21:14:07 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nb_size(unsigned int nb)
{
	size_t	size;

	size = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

char				*ft_itoa(int n)
{
	char			*s;
	unsigned int	nbr;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	size = (unsigned int)ft_nb_size(nbr);
	i = 0;
	if (!(s = (char*)ft_memalloc(size + 1 + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0 && (s[i] = '-'))
		size++;
	i = size - 1;
	while (nbr >= 10)
	{
		s[i] = (char)(nbr % 10 + '0');
		nbr = nbr / 10;
		i--;
	}
	s[i] = (char)(nbr % 10 + '0');
	s[size] = '\0';
	return (s);
}
