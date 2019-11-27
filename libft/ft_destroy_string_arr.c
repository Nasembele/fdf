/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_string_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:38:56 by soyster           #+#    #+#             */
/*   Updated: 2019/11/27 17:39:11 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_destroy_string_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
