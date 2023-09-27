/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:05:54 by shamzaou          #+#    #+#             */
/*   Updated: 2023/09/27 15:16:21 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 42

# define RESET "\x1B[0m"   // Reset color
# define RED "\x1B[31m"    // Red color
# define GREEN "\x1B[32m"  // Green color
# define YELLOW "\x1B[33m" // Yellow color

# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define PLUS 69
# define MINUS 78
# define SPACE 49
# define J_COLOR_UP 38
# define K_COLOR_DOWN 40

typedef struct s_gdata
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_gdata;

typedef struct s_plot
{
	int			x;
	int			y;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		real;
	double		imag;
	double		c_real;
	double		c_imag;
}				t_plot;

typedef struct s_custom_plot
{
	double		c_real;
	double		c_imag;
}				t_cus_plot;

typedef struct s_graphics
{
	void		*mlx;
	void		*win;
	int			set_num;
	double		zoom;
	int			color;
	int			cycle;
	t_gdata		*img;
	t_plot		*points;
	int			x;
	int			y;
	double		x_offset;
	double		y_offset;
	t_cus_plot	cus_pts;
}				t_graphics;

void			draw_set(int set_num, double real, double imag);
void			draw_fractal(t_graphics *graph);
void			mandel_draw(t_graphics *graph);
int				create_trgb(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b);
int				color_map(int value, int max_iter, int cycle);
int				mandel_helper(double real, double imag, int max_iter);
void			show_usage(void);

void			julia_draw(t_graphics *graph);
int				julia_helper(t_plot points, int max_iter);
void			my_mlx_pixel_put(t_gdata *data, int x, int y, int color);
int				expose_hook(t_graphics *graph);

int				key_press(int keycode, t_graphics *graph);
int				close_window(t_graphics *graph);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
double			ft_atod(const char *str);


int mouse_hook(int mouse_code, int x, int y, t_graphics *graph);
void	zoom(t_graphics *graph, int x, int y, int zoom);

#endif