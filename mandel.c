#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "minilibx_opengl_20191021/mlx.h"

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
    }
    return i;
}

int main(int argc, char **argv) {
    // set the window size and initialize mlx
    int width = 800, height = 600;
    void *mlx = mlx_init();
    void *window = mlx_new_window(mlx, width, height, "Mandelbrot Set");

    // allocate memory for the image buffer
    int *image = malloc(sizeof(int) * width * height);

    // generate the mandelbrot set and store it in the image buffer
    double xmin = -2.0, xmax = 1.0, ymin = -1.5, ymax = 1.5;
    double dx = (xmax - xmin) / width;
    double dy = (ymax - ymin) / height;
    int i, j;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            double x = xmin + i * dx;
            double y = ymin + j * dy;
            int iter = mandelbrot(x, y);
            double t = iter / 1000.0;
            image[j * width + i] = 0x010101 * (int)(255 * t * t);
        }
    }

    // create a new image from the image buffer and display it
    void *image_ptr = mlx_new_image(mlx, width, height);
    int bpp, size_line, endian;
    int *image_data = (int *)mlx_get_data_addr(image_ptr, &bpp, &size_line, &endian);
    memcpy(image_data, image, sizeof(int) * width * height);
    mlx_put_image_to_window(mlx, window, image_ptr, 0, 0);

    // wait for the user to close the window
    mlx_loop(mlx);

    // free memory and exit
    free(image);
    mlx_destroy_image(mlx, image_ptr);
    mlx_destroy_window(mlx, window);
    mlx_destroy_display(mlx);
    return 0;
}
