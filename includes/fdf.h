/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:06:04 by soyster           #+#    #+#             */
/*   Updated: 2019/11/28 17:52:55 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"

# include <math.h>
# include <fcntl.h>
# include "./libft.h"
# include "../resourses/minilibx/mlx.h"

# define WIDTH 		1300
# define HEIGHT		1300
# define EXIT  		53
# define PLUS  		69
# define MINUS		78
# define CHANGE		67

# define BLUE		720895
# define PURPLE 	9055202

# define RIGHT 		2
# define LEFT  		0
# define UP    		13
# define DOWN  		1

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
	int				gradient_flag;
	struct s_mlx	mlx;
	struct s_line	line;
	struct s_pos	pos;
}					t_map;

int					mouse_event(int keycode, int x, int y, t_map *map);
t_map				*ft_validation(int fd, int height);
int					ft_height(int fd);
int					ft_error(void);
static int			free_ft(char *line, char **arr_str, int f1, int f2);
static int			cycle_read(int fd, char *line, char **arr_str, t_map *map);
static int			first_read(int fd, char *line, char **arr_str, t_map *map);
int					delete_map(t_map **map, int i);
t_map				*create_map(int height);
static int			close_window(void *param);
static void			sidebar(t_map *map);
static void			calculate_z(int x, int y, t_map *map);
int					manage_paint(t_map *map);
int					create_window(t_map *map);
static void			add_start_pos(int *x0, int *y0, int key, t_map **map);
static void			drctn_processing(int x, int y, int direction, t_map **map);
static void			option_1(int x0, int y0, t_map **map);
static void			option_2(int x0, int y0, t_map **map);
void				bresenham(int x, int y, int direction, t_map **map);
static void			rotation_x(int *x, int *y, int *z, t_map **map);
static void			rotation_y(int *x, int *y, int *z, t_map **map);
static void			rotation_z(int *x, int *y, int *z, t_map **map);
void				iso(int *x, int *y, int *z, t_map **map);
static void			zoom(t_map *map, int keycode);
static void			recolor(t_map *map, int keycode);
static void			turn(t_map *map, int keycode);
int					keyboard_event(int keycode, t_map *map);
void				put_pixel(t_map **map, int x, int y, int color);
int					main(int argc, char **argv);

#endif
