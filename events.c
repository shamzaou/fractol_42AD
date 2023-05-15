/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:54:24 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 05:28:46 by shamzaou         ###   ########.fr       */
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

    graph->mouse_x = x; // Store the current mouse position
    graph->mouse_y = y; // Store the current mouse position

    draw_fractal(graph); 
    mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
    return (0);
}

int key_press(int keycode, t_graphics *graph)
{
    double move_factor = 0.1 * graph->zoom;
    if (keycode == 53)
        close_window(graph);
    else if (keycode == 40)
        graph->cycle += 5;
    else if (keycode == 38)
        graph->cycle -= 5;
    else if (keycode == 123) // Left arrow
        graph->x_offset -= move_factor;
    else if (keycode == 126) // Up arrow
        graph->y_offset -= move_factor;
    else if (keycode == 124) // Right arrow
        graph->x_offset += move_factor;
    else if (keycode == 125) // Down arrow
        graph->y_offset += move_factor;
    
    draw_fractal(graph);
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

