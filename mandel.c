/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:33:44 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/08 20:58:25 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
<<<<<<< HEAD
#include "mlx/mlx.h"

// define the mandelbrot function
int mandelbrot(double x, double y) {
    double zx = 0, zy = 0;
    double zx2 = 0, zy2 = 0;
    int i;
    for (i = 0; i < 1000; i++) {
        zy = 2 * zx * zy + y;
        zx = zx2 - zy2 + x;
        zx2 = zx * zx;
        zy2 = zy * zy;
        if (zx2 + zy2 > 4) {
            return i;
        }
=======
#include "minilibx-linux/mlx.h"
//#include "minilibx_opengl_20191021/mlx.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000


// ==================== EVENTS HERE =======================

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int    close_win(void *mlx, void *window)
{
    printf("About to close !\n");
    mlx_destroy_window(mlx, window);
    printf("closed window!\n");
    return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	//mlx_key_hook(vars.win, close, &vars);
    int i = 0;
    //mlx_key_hook(vars.win, close_win, &vars);
    mlx_hook(vars.win, 4, 0, close_win, &vars);
    printf("func passed!\n");
	//mlx_loop(vars.mlx);
    
}

// =============== DRAWING AND COLORS ========================

/*
int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b) {
    return (*(int *)(unsigned char[4]){b, g, r, t});
}

int mandelbrot(double real, double imag, int max_iter) {
    double r = 0, i = 0;
    int iter = 0;

    while (r * r + i * i <= 4 && iter < max_iter) {
        double temp = r * r - i * i + real;
        i = 2 * r * i + imag;
        r = temp;
        iter++;
>>>>>>> 4e3f54a13377e7c63836ea8db3640f15fa74620a
    }
}
/* nice coloring function
int color_map(int value, int max_iter) {
    int r, g, b;
    double t = (double)value / max_iter;

    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return create_trgb(0, r, g, b);
}
*/
/*
// COLOR CYCLING. SHOULD BE USED TO CYCLE BETWEEN COLORS LATER..
int color_map(int value, int max_iter) {
    int r, g, b;
    int cycle = 1000;

    r = (value * 2) % cycle;
    g = (value * 5) % cycle;
    b = (value * 10) % cycle;

    return create_trgb(0, r, g, b);
}




int main() {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Set");

    double x_min = -2, x_max = 1, y_min = -1, y_max = 1;
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double real = x_min + (x * (x_max - x_min)) / WIDTH;
            double imag = y_min + (y * (y_max - y_min)) / HEIGHT;

            int value = mandelbrot(real, imag, MAX_ITER);
            int color = color_map(value, MAX_ITER);

            mlx_pixel_put(mlx, win, x, y, color);
        }
    }

    mlx_loop(mlx);
    return 0;
}
*/