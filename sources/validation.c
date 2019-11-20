/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/21 00:12:53 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map   *ft_validation(int fd, int height)
{
    t_map   *map;

    if (!(map = ft_create_map(height)))
        return(0);
            
}   