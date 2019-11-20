/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/20 23:14:28 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"

# include <math.h>
#include <fcntl.h>
# include "./libft.h"
# include "../resourses/minilibx/mlx.h"

# define WIDTH 		1300
# define HEIGHT		1300

struct				s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					;

struct				s_line
{
	int				a;
	int				b;
	int				x0;
	int				y0;
	int				z0;
	int				x1;
	int				y1;
	int				z1;
	int				f;
	int				key_a;
	int				key_b;
}					;

struct				s_pos
{
	int				min_z;
	int				max_z;
	int				start_x;
	int				start_y;
	int				center_x;
	int				center_y;
	int				scroll;
	double			alpha;
	double			beta;
	double			gamma;
	int				zoom;
}					;

typedef struct		s_map
{
	int				**arr;
	int				height;
	int				width;
	int				color;
	int				sidebar_flag;
//	int				gradient_flag;
	struct s_mlx	mlx;
	struct s_line	line;
	struct s_pos	pos;
}					t_map;

int ft_height(int fd);
int ft_error(void);
int main(int argc, char **argv);



#endif