/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:07:57 by shamzaou          #+#    #+#             */
/*   Updated: 2023/09/27 21:09:35 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// static	int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// static int ft_isdigit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	i = 0;
	result = 0;
	if (str == NULL)
		return (-42);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-42);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result > UINT_MAX)
			return (-42);
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-42);
	return (result);
}

// static int is_valid(const char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] == ' ' || str[i] == '\t')
//         i++;
//     while (str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
//         i++;
//     if (str[i] == '.')
//         i++;
//     while (str[i] >= '0' && str[i] <= '9')
//         i++;
//     while (str[i] == ' ' || str[i] == '\t')
//         i++;
    
// }

double ft_atof(char *s)
{
    // Skip leading whitespace
    while (*s == ' ' || *s == '\t')
        s++;

    // Check for a sign
    int sign = 1;
    if (*s == '-' || *s == '+') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }

    // Parse the integer part
    double result = 0.0;
    while (*s >= '0' && *s <= '9') {
        result = result * 10.0 + (*s - '0');
        s++;
    }

    // Check for a decimal point
    if (*s == '.') {
        s++;
        double divisor = 10.0;
        while (*s >= '0' && *s <= '9') {
            result += (*s - '0') / divisor;
            divisor *= 10.0;
            s++;
        }
    }

    // Handle any remaining non-numeric characters
    while (*s != '\0') {
        if (*s != ' ' && *s != '\t') {
            // Error: Non-numeric character found
            return NAN; // Not-a-Number to indicate an error
        }
        s++;
    }

    // Apply the sign
    return result * sign;
}