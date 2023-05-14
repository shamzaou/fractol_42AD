/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:05:54 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/14 10:31:42 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

#define RESET   "\x1B[0m"     // Reset color
#define RED     "\x1B[31m"    // Red color
#define GREEN   "\x1B[32m"    // Green color
#define YELLOW  "\x1B[33m"    // Yellow color

typedef struct	s_gdata {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_gdata;

typedef struct s_plot
{
    int     x;
    int     y;
    double  x_min;
    double  x_max;
    double  y_min;
    double  y_max;
	double	real;
	double	imag;
	double	c_real;
	double	c_imag;
}				t_plot;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		set_num;
	double	zoom;
	t_gdata	*img;
	t_plot	*points;
}				t_graphics;

void 	draw_set(int set_num);
void 	mandel_draw(t_gdata *img, double zoom);
int 	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
int 	color_map(int value, int max_iter);
int 	mandel_helper(double real, double imag, int max_iter);

void 	julia_draw(t_gdata *img);
int 	julia_helper(t_plot points, int max_iter);
void	my_mlx_pixel_put(t_gdata *data, int x, int y, int color);
int		expose_hook(t_graphics *graph);
int     mouse_scroll(int button, int x, int y, t_graphics *graph);
void 	ft_putstr(char *str);
int		ft_atoi(char *str);

#endif