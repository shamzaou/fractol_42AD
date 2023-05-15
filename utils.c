/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:07:57 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/15 08:09:48 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <string.h>
#include <limits.h>

int expose_hook(t_graphics *graph)
{
    mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);    return (0);
}
void	my_mlx_pixel_put(t_gdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
    return (*(int *)(unsigned char[4]){b, g, r, t});
}

// int color_map(int value, int max_iter)
// {
//     int 	r;
// 	int 	g;
// 	int 	b;
//     double	t;

// 	t = (double)value / max_iter;
//     r = (int)(9 * (1 - t) * t * t * t * 255);
//     g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
//     return create_trgb(0, r, g, b);
// }

// FUNC FOR CYCLING TO BE USED WITH KEY HOOKS
int color_map(int value, int max_iter, int cycle) {
    int r, g, b;
    double t;

	if (!(cycle >= -max_iter && cycle < max_iter))
		cycle = 0;
	t = (double)value / (max_iter - cycle);
    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (create_trgb(0, r, g, b));
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static int	skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

static int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

int	ft_atoi(char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = skip_space(str);
	if(str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (-1);
		i++;
	}
	return (result);
}

double ft_atod(const char *str)
{
    double result;
    double sign;
    double decimal_factor;
    bool decimal_point;

    result = 0.0;
    sign = 1.0;
    decimal_factor = 1.0;
    decimal_point = false;
    while (isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1.0;
        str++;
    }
    while ((*str >= '0' && *str <= '9') || *str == '.')
    {
        if (*str == '.')
        {
            if (decimal_point)
                break ;
            decimal_point = true;
        }
        else
        {
            if (decimal_point)
                decimal_factor *= 0.1;
            result = result * 10.0 + (*str - '0');
        }
        str++;
    }
    return (sign * result * decimal_factor);
}
