/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:34:51 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/26 18:25:04 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(int x, double c)
{
	if (x <= 0)
		return (0);
	return (exp2(mandelbrot(x - 1, c)) + c);
}

double mandelbrot_x(int n, double a)
{
	if (n <= 1)
		return (0);
	return (mandelbrot_x(n - 1, a) * mandelbrot_x(n - 1, a)  - mandelbrot_y(n - 1, a) * mandelbrot_y(n - 1, a)) + a;
}

double mandelbrot_y(int n, double b)
{
	if (n <= 1)
		return (0);
	return (2 * mandelbrot_x(n - 1, b) * mandelbrot_y(n - 1, b) + b);
}