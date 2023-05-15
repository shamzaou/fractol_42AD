/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:57:38 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 06:11:02 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

#define RESET   "\x1B[0m"     // Reset color
#define RED     "\x1B[31m"    // Red color
#define GREEN   "\x1B[32m"    // Green color
#define YELLOW  "\x1B[33m"    // Yellow color

int     main(int ac, char **av)
{
    int args;

    if (av[1])
        args = ft_atoi(av[1]);
    if (ac != 2 || (args != 1 && args != 2))
    {
        ft_putstr(RED "ERROR: Wrong arguments.\n" RESET);
        ft_putstr(YELLOW "Usage: ./fractol [fractal_number]\n" RESET);
        ft_putstr(GREEN "Available fractals:\n" RESET);
        ft_putstr(GREEN "Type '1' for the Mandelbrot set.\n" RESET);
        ft_putstr(GREEN "Type '2' for the Julia set.\n" RESET);
        exit(1);
    }
    else
        draw_set(args);
}

void draw_set(int set_num)
{
    t_graphics  graph;
    t_gdata     img;

    graph.mlx = mlx_init();
    graph.win = mlx_new_window(graph.mlx, WIDTH, HEIGHT, "THE FRACTOL PROJECT");
    graph.set_num = set_num;
    graph.img = &img;
    graph.zoom = 1.0;
    graph.cycle = 1;
    graph.x_offset = 0.0;
    graph.y_offset = 0.0;
    img.img = mlx_new_image(graph.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    draw_fractal(&graph);
    
    mlx_hook(graph.win, 4, 1L << 2, mouse_scroll, &graph);
    mlx_hook(graph.win, 2, 1L << 0, key_press, &graph);
    mlx_hook(graph.win, 17, 1L << 17, close_window, &graph);
    // mlx_hook(graph.win, 12, 1L << 15, expose_hook, &graph);
    // mlx_put_image_to_window(graph.mlx, graph.win, img.img, 0, 0);
    mlx_loop(graph.mlx);
}

void draw_fractal(t_graphics *graph)
{
    if (graph->set_num == 1)
    {
        ft_putstr(GREEN "Mandelbrot set\n" RESET);
        mandel_draw(graph, graph->mouse_x, graph->mouse_y);
    }
    else if (graph->set_num == 2)
    {
        ft_putstr(GREEN "Julia set\n" RESET);
        julia_draw(graph, graph->mouse_x, graph->mouse_y);
    }
    mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
}

