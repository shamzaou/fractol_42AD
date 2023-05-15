/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:57:38 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 08:13:48 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

#define RESET   "\x1B[0m"     // Reset color
#define RED     "\x1B[31m"    // Red color
#define GREEN   "\x1B[32m"    // Green color
#define YELLOW  "\x1B[33m"    // Yellow color

int main(int argc, char **argv)
{
    int arg;
    double real;
    double imag;
    
    if (argc == 2)
    {
        arg = ft_atoi(argv[1]);
        if (arg == 1 || arg == 2)
            draw_set(arg, 0, 0);
        else
            show_usage();
    }
    else if (argc == 4 && ft_atoi(argv[1]) == 2)
    {
        real = ft_atod(argv[2]);
        imag = ft_atod(argv[3]);
        if (real >= -2.0 && real <= 2.0 && imag >= -2.0 && imag <= 2.0)
            draw_set(2, real, imag);
        else
            show_usage();
    }
    else
        show_usage();
    return (0);
}

void show_usage(void)
{
    ft_putstr(RED "ERROR: Wrong arguments.\n" RESET);
    ft_putstr(YELLOW "Usage: ./fractol [fractal_number]\n" RESET);
    ft_putstr(GREEN "Available fractals:\n" RESET);
    ft_putstr(GREEN "Type '1' for the Mandelbrot set.\n" RESET);
    ft_putstr(GREEN "Type '2' for the default Julia set.\n" RESET);
    ft_putstr(GREEN "For custom Julia set, type '2' followed by chosen \n" RESET);
    ft_putstr(GREEN "complex parameters. Example : ./fractol 2 -0.835 -2321 \n" RESET);
    ft_putstr("Both the real and imaginary parts must be in a [-2, 2] range.");
    exit(1);
}


void draw_set(int set_num, double real, double imag)
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
    graph.cus_pts.c_real = real;
    graph.cus_pts.c_imag = imag;
    img.img = mlx_new_image(graph.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    draw_fractal(&graph, real, imag);
    
    mlx_hook(graph.win, 4, 1L << 2, mouse_scroll, &graph);
    mlx_hook(graph.win, 2, 1L << 0, key_press, &graph);
    mlx_hook(graph.win, 17, 1L << 17, close_window, &graph);
    // mlx_hook(graph.win, 12, 1L << 15, expose_hook, &graph);
    // mlx_put_image_to_window(graph.mlx, graph.win, img.img, 0, 0);
    mlx_loop(graph.mlx);
}

void draw_fractal(t_graphics *graph, double real, double imag)
{
    t_cus_plot cus_p;
    
    cus_p.c_real = real;
    cus_p.c_imag = imag;
    if (graph->set_num == 1)
    {
        ft_putstr(GREEN "Mandelbrot set\n" RESET);
        mandel_draw(graph, graph->mouse_x, graph->mouse_y);
    }
    else if (graph->set_num == 2)
    {
        ft_putstr(GREEN "Julia set\n" RESET);
        julia_draw(graph, graph->mouse_x, graph->mouse_y, cus_p);
    }
    mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
}

