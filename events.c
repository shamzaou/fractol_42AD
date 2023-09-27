/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:54:24 by shamzaou          #+#    #+#             */
/*   Updated: 2023/09/27 14:48:47 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int mouse_code, int x, int y, t_graphics *graph)
{
	x = x*1;
	y = y*1;
	if (mouse_code == SCROLL_UP)
		graph->zoom *= 1.5;
	else if (mouse_code == SCROLL_DOWN)
		graph->zoom *= 0.5;
	draw_fractal(graph);
	return (0);
}

// void	zoom(t_graphics *graph, int x, int y, int zoom)
// {
// 	double	zoom_level;

// 	zoom_level = 1.42;
// 	if (zoom == 1)
// 	{
// 		graph->x_offset = (x / graph->zoom + graph->x) - (x
// 				/ (graph->zoom * zoom_level));
// 		graph->y_offset = (y / graph->zoom + graph->y_offset) - (y
// 				/ (graph->zoom * zoom_level));
// 		graph->zoom *= zoom_level;
// 	}
// 	else if (zoom == -1)
// 	{
// 		graph->x_offset = (x / graph->zoom + graph->x_offset) - (x
// 				/ (graph->zoom / zoom_level));
// 		graph->y_offset = (y / graph->zoom + graph->y_offset) - (y
// 				/ (graph->zoom / zoom_level));
// 		graph->zoom /= zoom_level;
// 	}
// 	else
// 		return ;
// }

// int mouse_move(int x, int y, t_graphics *graph)
// {
// 	if (graph->x == 0 && graph->y == 0)
// 	{
// 		graph->x = x;
// 		graph->y = y;
// 		return (0);
// 	}
// 	graph->cus_pts.c_real += (x - graph->x) * 0.0001;
// 	graph->cus_pts.c_imag += (y - graph->y) * 0.0001;
// 	graph->x = x;
// 	graph->y = y;
// 	draw_fractal(graph, graph->cus_pts.c_real, graph->cus_pts.c_imag);
// 	mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
// 	return (0);
// }

// int mouse_zoom(int button, int x, int y, t_graphics *graph)
// {
//     double zoom_factor = 0.9;
// 	x = x * 1;
// 	y = y * 1;
//     if (button == 4)
//     {
//         // Zoom in at the center of the image
//         graph->zoom *= zoom_factor;

//     }
//     else if (button == 5)
//     {
//         // Zoom out at the center of the image
//         graph->zoom /= zoom_factor;

//     }
//     else
//         return (1);

//     draw_fractal(graph, graph->cus_pts.c_real, graph->cus_pts.c_imag);
//     mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
//     return (0);
// }



/*
int	mouse_scroll(int button, int x, int y, t_graphics *graph)
{
	double	zoom_factor;

	zoom_factor = 0.9;
	if (button == 4)
		graph->zoom *= zoom_factor;
	else if (button == 5)
		graph->zoom /= zoom_factor;
	else
		return (1);
	//graph->x = x;
	//graph->y = y;
	draw_fractal(graph, graph->cus_pts.c_real, graph->cus_pts.c_imag);
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
	return (0);
}*/

int	key_press(int keycode, t_graphics *graph)
{
	double	move_factor;
	
	move_factor = 1;
	move_factor /= graph->zoom * 10;
	if (keycode == ESC)
		close_window(graph);
	else if (keycode == J_COLOR_UP)
		graph->cycle += 4;
	else if (keycode == K_COLOR_DOWN)
		graph->cycle -= 4;
	else if (keycode == LEFT_ARROW)
		graph->x_offset -= move_factor;
	else if (keycode == UP_ARROW)
		graph->y_offset -= move_factor;
	else if (keycode == RIGHT_ARROW)
		graph->x_offset += move_factor;
	else if (keycode == DOWN_ARROW)
		graph->y_offset += move_factor;
	else
		return (1);
	draw_fractal(graph);
	//mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
	return (0);
}

int	close_window(t_graphics *graph)
{
	ft_putstr(RED "... Program closing ...\n" RESET);
	mlx_clear_window(graph->mlx, graph->win);
	mlx_destroy_window(graph->mlx, graph->win);
	exit(0);
	return (0);
}
