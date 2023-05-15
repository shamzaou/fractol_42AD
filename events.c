/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:54:24 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 12:38:54 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_scroll(int button, int x, int y, t_graphics *graph)
{
    double zoom_factor = 1.1;

    if (button == 4)
        graph->zoom *= zoom_factor;
    else if (button == 5)
        graph->zoom /= zoom_factor;
    else
        return(1);
    graph->mouse_x = x;
    graph->mouse_y = y;

    draw_fractal(graph, graph->cus_pts.c_real, graph->cus_pts.c_imag); 
    mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
    return (0);
}

int key_press(int keycode, t_graphics *graph)
{
    double move_factor = 0.1 * graph->zoom;
    if (keycode == 53)
        close_window(graph);
    else if (keycode == 40)
        graph->cycle += 4;
    else if (keycode == 38)
        graph->cycle -= 4;
    else if (keycode == 123) // Left arrow
        graph->x_offset -= move_factor;
    else if (keycode == 126) // Up arrow
        graph->y_offset -= move_factor;
    else if (keycode == 124) // Right arrow
        graph->x_offset += move_factor;
    else if (keycode == 125) // Down arrow
        graph->y_offset += move_factor;
    else
        return(1);
    draw_fractal(graph, graph->cus_pts.c_real, graph->cus_pts.c_imag);
    mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
    return (0);
}

int close_window(t_graphics *graph)
{
    mlx_clear_window(graph->mlx, graph->win);
    mlx_destroy_window(graph->mlx, graph->win);
    exit(0);
    return (0);
}

