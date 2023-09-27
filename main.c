/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:57:38 by shamzaou          #+#    #+#             */
/*   Updated: 2023/09/27 14:46:19 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int		arg;
	double	real;
	double	imag;

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

void	show_usage(void)
{
	ft_putstr(RED "ERROR: Wrong arguments.\n" RESET);
	ft_putstr(YELLOW "Usage: ./fractol [fractal_number]\n" RESET);
	ft_putstr(GREEN "Available fractals:\n" RESET);
	ft_putstr(GREEN "Type '1' for the Mandelbrot set.\n" RESET);
	ft_putstr(GREEN "Type '2' for the default Julia set.\n" RESET);
	ft_putstr(GREEN "For a custom Julia set, type '2' followed " RESET);
	ft_putstr(GREEN "by chosen complex parameters. Example : " RESET);
	ft_putstr(GREEN "./fractol 2 -0.835 -0.2321 \n" RESET);
	ft_putstr("Both the real and imaginary parts must be in a [-2,2] range.\n");
	exit(1);
}

void	draw_set(int set_num, double real, double imag)
{
	t_graphics	graph;
	t_gdata		img;

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
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_fractal(&graph);

	//mlx_hook(graph.win, 6, 0, mouse_move, &graph);
	//mlx_hook(graph.win, 4, 0, mouse_scroll, &graph);
	//mlx_hook(graph.win, 4, 0, mouse_zoom, &graph);
	mlx_mouse_hook(graph.win, mouse_hook, &graph);

	mlx_hook(graph.win, 2, 0, key_press, &graph);
	mlx_hook(graph.win, 17, 0, close_window, &graph);
	//mlx_hook(graph.win, 12, 1L << 15, expose_hook, &graph);
	mlx_loop(graph.mlx);
}

void	draw_fractal(t_graphics *graph)
{
	if (graph->set_num == 1)
	{
		ft_putstr(GREEN "Mandelbrot set rendering ...\n" RESET);
		mandel_draw(graph);
	}
	else if (graph->set_num == 2)
	{
		ft_putstr(GREEN "Julia set rendering ...\n" RESET);
		julia_draw(graph);
	}
	//mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
}
