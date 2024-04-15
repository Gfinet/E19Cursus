/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:03:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/15 16:06:49 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	zoom_in(int x, int y, t_fract *f)
{
	f->coef /= 1.1;
	if (f->mv.follow_m)
	{
		f->start_x += (x - f->start_x) * (1 - 1.1);
		f->start_y += (f->start_y - y) * (1 - 1.1);
	}
	else
	{
		f->start_x += (WIN_WIDTH / 2 - f->start_x) * (1 - 1.1);
		f->start_y += (WIN_HEIGHT / 2 - f->start_y) * (1 - 1.1);
	}
}

void	zoom_out(int x, int y, t_fract *f)
{
	f->coef *= 1.1;
	if (f->mv.follow_m)
	{
		f->start_x += (x - f->start_x) * (1 - 1 / 1.1);
		f->start_y += (f->start_y - y) * (1 - 1 / 1.1);
	}
	else
	{
		f->start_x += (WIN_WIDTH / 2 - f->start_x) * (1 - 1 / 1.1);
		f->start_y += (WIN_HEIGHT / 2 - f->start_y) * (1 - 1 / 1.1);
	}
}

void	set_color(t_fract *f, int x, int y, int it)
{
	unsigned int	color;

	if (!f->mv.b_color)
	{
		color = 0xFFFFFFFF / ((it + 1) * f->mv.color);
		my_mlx_pixel_put(&f->img, x, y, color);
	}
	else if (f->mv.b_color == 1)
	{
		color = 0x00000000 + ((it + f->mv.color) * 0x00010101);
		my_mlx_pixel_put(&f->img, x, y, color);
	}
	else
	{
		color = 0x00FF00FF + ((it + f->mv.color) * 0x000F000F);
		my_mlx_pixel_put(&f->img, x, y, color);
	}
}
