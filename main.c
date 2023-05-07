#include "mlx.h"
#include <complex.h>
#include <stdio.h>

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITER 1000


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Convert pixel coordinates to complex numbers
double complex pixel_to_complex(int x, int y)
{
    double real = (double)x / (double)WIDTH * 3.5 - 2.5;
    double imag = (double)y / (double)HEIGHT * 2.0 - 1.0;
    return real + imag * I;
}

// Mandelbrot algorithm
int mandelbrot(double complex c)
{
    int iter = 0;
    double complex z = 0;
    while (cabs(z) < 2.0 && iter < MAX_ITER)
    {
        z = z * z + c;
        iter++;
    }
    return iter;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            double complex c = pixel_to_complex(x, y);
            // int iter = mandelbrot(c);
            // int color = iter % 256;
            // In this example, we use a simple grayscale gradient based on the number of iterations.
            // You can replace this with more advanced color schemes if desired.
            my_mlx_pixel_put(&img, x, y, create_trgb(5000, 0x00FF0000, 0x0000FF00, 0x000000FF));
        }
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
