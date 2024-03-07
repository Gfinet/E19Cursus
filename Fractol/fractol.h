/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/07 03:25:23 by Gfinet           ###   ########.fr       */
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

typedef struct s_vec {
	double x;
	double y;
}	t_vec;

typedef struct s_fract
{
	t_data img;
	void *mlx;
	void *win;
	t_vec z;
	t_vec c;
	int start_x;
	int start_y;
}	t_fract;

double	mandelbrot(int x, double c);
double mandelbrot_x(int n, double a);
double mandelbrot_y(int n, double b);
int esc_handle(int key, t_fract *f);
int	key_event(int keycode, t_fract *f);
t_vec compute_next(t_vec cur, t_vec cons);


#endif