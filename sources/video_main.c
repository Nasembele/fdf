#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 1000
#define HEIGHT 1000

void    ft_exit(char *msg)
{
    ft_putstr(msg);
    ft_putchar('\n');
    exit (0);
}

int key_event(int keycode, void *param)
{
    if (keycode == 53)
        ft_exit("Exit");
    return (0);
}

void    put_pixel(int x, int y, int color, int *data)
{
    data[y * WIDTH + x] = color;
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     *data;
    int     bpp;
    int     size_l;
    int     endian;


    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "42");
    img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_l, &endian);
    put_pixel(250, 250, 0xFFFFFF, data);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_key_hook(win_ptr, key_event, (void *)0);
    mlx_loop(mlx_ptr);
}
