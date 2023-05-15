/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:02:05 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 08:20:28 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    julia_init(t_graphics *graph, t_plot *p, t_cus_plot cus_pts)
{
    p->y = -1;
    p->x_min = -2 + graph->x_offset;
    p->x_max = 2 + graph->x_offset;
    p->y_min = -2 + graph->y_offset;
    p->y_max = 2 + graph->y_offset;
    p->c_real = -0.8;
    p->c_imag = 0.156;
    p->c_real = cus_pts.c_real;
    p->c_imag = cus_pts.c_imag;
}

void julia_draw(t_graphics *graph, int mouse_x, int mouse_y, t_cus_plot cus_pts)
{
    t_gdata     *img;
    double      zoom;
    t_plot      p;
    int         value;
    int         color;

    img = graph->img;
    zoom = graph->zoom;
    julia_init(graph, &p, cus_pts);
    while (++p.y < HEIGHT)
    {
        p.x = -1;
        while(++p.x < WIDTH)
        {
            p.real = p.x_min + ((p.x - mouse_x) * (p.x_max - p.x_min) / WIDTH * zoom + (double)mouse_x / WIDTH * (p.x_max - p.x_min));
            p.imag = p.y_min + ((p.y - mouse_y) * (p.y_max - p.y_min) / HEIGHT * zoom + (double)mouse_y / HEIGHT * (p.y_max - p.y_min));
            value = julia_helper(p, MAX_ITER);
            color = color_map(value, MAX_ITER, graph->cycle);
            my_mlx_pixel_put(img, p.x, p.y, color);
        }
    }
}

int julia_helper(t_plot points, int max_iter)
{
    double  r;
    double  i;
    double  temp;
    int     iter;

    r = points.real;
    i = points.imag;
    iter = 0;

    while (r * r + i * i <= 4 && iter < max_iter)
    {
        temp = r * r - i * i + points.c_real;
        i = 2 * r * i + points.c_imag;
        r = temp;
        iter++;
    }
    return (iter);
}