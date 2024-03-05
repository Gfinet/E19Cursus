/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/05 01:08:06 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "Printf/ft_printf.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct t_vec {
	double x;
	double y;
}	t_vec;

double	mandelbrot(int x, double c);
double mandelbrot_x(int n, double a);
double mandelbrot_y(int n, double b);
int esc_handle(void *mlx, void *win);
t_vec compute_next(t_vec cur, t_vec cons);


#endif