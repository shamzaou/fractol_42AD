/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:02:05 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/14 09:07:52 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_draw(t_gdata *img)
{
    t_plot  p;
    int     value;
    int     color;

    p.y = -1;
    p.x_min = -2;
    p.x_max = 2;
    p.y_min = -2;
    p.y_max = 2;
    p.c_real = -0.8;
    p.c_imag = 0.156;
    while (++p.y < HEIGHT)
    {
        p.x = -1;
        while(++p.x < WIDTH)
        {
            p.real = p.x_min + (p.x * (p.x_max - p.x_min) / WIDTH);
            p.imag = p.y_min + (p.y * (p.y_max - p.y_min) / HEIGHT);
            value = julia_helper(p, MAX_ITER);
            color = color_map(value, MAX_ITER);
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