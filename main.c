/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:57:38 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/10 10:05:49 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

int    close_win(t_vars mlx)
{
    mlx_destroy_window(mlx.mlx, mlx.win);
    return (0);
}

int     main()
{
    t_vars mlx;
    t_data img;
    
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "My test window !!");
    img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    int x = 100;
    int y = 100;
    int col = 0;
    while (x <= 300)
    {
        my_mlx_pixel_put(&img, x, 100, 0x00FF0000 >> col);
        my_mlx_pixel_put(&img, x, 300, 0x00FF0000 >> col);
        my_mlx_pixel_put(&img, 100, y, 0x00FF0000 >> col);
        my_mlx_pixel_put(&img, 300, y, 0x00FF0000 >> col);
        x++;
        y++;
        col++;
    }
    mlx_mouse_hook(mlx.win, close_win, &mlx);
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
    mlx_loop(mlx.mlx);
}
