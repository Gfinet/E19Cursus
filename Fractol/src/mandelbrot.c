/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:34:51 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/14 00:11:18 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_vec	compute_next(t_vec cur, t_vec cons)
{
	t_vec	res;

	res.x = cur.x * cur.x - cur.y * cur.y;
	res.y = 2.0 * cur.x * cur.y;
	res.x += cons.x;
	res.y += cons.y;
	return (res);
}

double	compute_mand(t_fract *f)
{
	double	i;
	t_vec	p;

	i = 0;
	p.x = f->z.x;
	p.y = f->z.y;
	while (p.x * p.x + p.y * p.y < 2.0 && i < f->max_it)
	{
		p = compute_next(p, f->z);
		i++;
	}
	return (i);
}

double	compute_julia(t_fract *f)
{
	double	i;
	t_vec	p;

	i = 0;
	p.x = f->z.x;
	p.y = f->z.y;
	while (p.x * p.x + p.y * p.y < 2.0 && i < f->max_it)
	{
		p = compute_next(p, f->c);
		i++;
	}
	return (i);
}

//color = 0x00FFFFFF - ((it + f->mv.color) * 0x00010101);
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

/*
			if (x == WIN_WIDTH / 2 && y == WIN_HEIGHT / 2)
				printf("z.x = %f\nz.y = %f\n\n", f->z.x, f->z.y);
*/

void	draw_fract(t_fract *f)
{
	double	it;
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			f->z.x = (double)(2 * (x - f->start_x)) / (f->coef);
			f->z.y = (double)(2 * (y - f->start_y)) / (f->coef);
			if (f->mv.julia_mandel)
				it = compute_mand(f);
			else
				it = compute_julia(f);
			set_color(f, x, y, it);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
