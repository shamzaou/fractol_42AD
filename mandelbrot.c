/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:17:48 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 05:14:21 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandel_draw(t_graphics *graph, int mouse_x, int mouse_y)
{
    t_gdata *img;
    double zoom;
    t_plot  p;
    int     value;
    int     color;

    img = graph->img;
    zoom = graph->zoom;
    p.y = -1;
    p.x_min = -2 + graph->x_offset;
    p.x_max = 1 + graph->x_offset;
    p.y_min = -1 + graph->y_offset;
    p.y_max = 1 + graph->y_offset;
    while (++p.y < HEIGHT)
    {
        p.x = -1;
        while(++p.x < WIDTH)
        {
            p.real = p.x_min + (p.x - mouse_x) * (p.x_max - p.x_min) / WIDTH * zoom + (double)mouse_x / WIDTH * (p.x_max - p.x_min);
            p.imag = p.y_min + (p.y - mouse_y) * (p.y_max - p.y_min) / HEIGHT * zoom + (double)mouse_y / HEIGHT * (p.y_max - p.y_min);
            value = mandel_helper(p.real, p.imag, MAX_ITER);
            color = color_map(value, MAX_ITER, graph->cycle);
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
