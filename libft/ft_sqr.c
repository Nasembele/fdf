/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 02:42:56 by soyster           #+#    #+#             */
/*   Updated: 2019/04/23 03:19:51 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqr(int nbr, int power)
{
	int	prev;
	int	save;

	save = nbr;
	while (power > 1)
	{
		prev = nbr;
		nbr = nbr * save;
		if (prev > nbr)
			return (save < 0 ? 0 : -1);
		power--;
	}
	return (nbr);
}
