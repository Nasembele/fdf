/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:10:42 by soyster           #+#    #+#             */
/*   Updated: 2019/04/23 03:05:53 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_factorial(int nb)
{
	int ans;

	ans = 1;
	if (nb > 0)
	{
		while (nb > 0)
		{
			ans = ans * nb;
			if (ans > 2147483647)
				return (0);
			nb--;
		}
	}
	else
	{
		if (nb == 0)
			return (1);
		else
			return (0);
	}
	return (ans);
}
