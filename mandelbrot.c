/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:17:48 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/14 10:31:27 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandel_draw(t_gdata *img, double zoom)
{
    t_plot  p;
    int     value;
    int     color;

    p.y = -1;
    p.x_min = -2;
    p.x_max = 1;
    p.y_min = -1;
    p.y_max = 1;
    while (++p.y < HEIGHT)
    {
        p.x = -1;
        while(++p.x < WIDTH)
        {
            p.real = p.x_min + (p.x * (p.x_max - p.x_min) / WIDTH * zoom);
            p.imag = p.y_min + (p.y * (p.y_max - p.y_min) / HEIGHT * zoom);
            value = mandel_helper(p.real, p.imag, MAX_ITER);
            color = color_map(value, MAX_ITER);
            my_mlx_pixel_put(img, p.x, p.y, color);
        }
    }
}

int mandel_helper(double real, double imag, int max_iter)
{
    double  r;
    double  i;
    double  temp;
    int     iter;

    r = 0;
    i = 0;
    iter = 0;

    while (r * r + i * i <= 4 && iter < max_iter)
    {
        temp = r * r - i * i + real;
        i = 2 * r * i + imag;
        r = temp;
        iter++;
    }
    return (iter);
}
