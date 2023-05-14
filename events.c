/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:54:24 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/14 12:20:16 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     mouse_scroll(int button, int x, int y, t_graphics *graph)
{
    double  zoom_factor;

    zoom_factor = 1.1;
    if (button == 4)
        graph->zoom *= zoom_factor;
    else if ( button == 5)
        graph->zoom /= zoom_factor;
    draw_set(graph->set_num);
    return (0);
}