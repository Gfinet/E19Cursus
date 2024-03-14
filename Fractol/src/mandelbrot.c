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

t_vec compute_next(t_vec cur, t_vec cons)
{
	t_vec res;

	res.x = cur.x * cur.x - cur.y * cur.y;
	res.y = 2.0 * cur.x * cur.y;
	res.x += cons.x;
	res.y += cons.y;
	return (res);
}

double mod2(t_vec z)
{
	return (z.x * z.x + z.y * z.y);
}

double compute_mand(t_fract *f)
{
	double i;
	t_vec p;

	i = 0;
	p.x = f->z.x;
	p.y = f->z.y;
	while (mod2(p) < 2.0 && i < f->max_it)
	{
		p = compute_next(p, f->z);
		i++;
	}
	return (i);
}

double compute_julia(t_fract *f)
{
	double i;
	t_vec p;

	i = 0;
	p.x = f->z.x;
	p.y = f->z.y;
	while (mod2(p) < 2.0 && i < f->max_it)
	{
		p = compute_next(p, f->c);
		i++;
	}
	return (i);
}

void set_color(t_fract *f, int x, int y, int it)
{
	unsigned int color;
	if (f->mv.b_color)
	{
		color = 0x00FFFFFF - ((it + f->mv.color ) * 0x00010101);
		my_mlx_pixel_put(&f->img, x, y, color );// / ((it + 1) * f->mv.color));
	}
	else
	{
		color = 0xFFFFFFFF / ((it + 1 ) * f->mv.color );
		my_mlx_pixel_put(&f->img, x, y, color );// / ((it + 1) * f->mv.color));
	}
}

void draw_fract(t_fract *f)
{
	double it;
	int x;
	int y;

	y = 0;
	//printf("C.r = %f\nC.i = %f\n",f->c.x, f->c.y);
	//printf("coef = %f\n", f->coef);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			f->z.x = (double)((x - f->start_x)) / (f->coef / 2);
			f->z.y = (double)((y - f->start_y)) / (f->coef / 2);
			if (f->mv.julia_mandel)
				it = compute_mand(f);
			else
				it = compute_julia(f);
			//printf("x - st_x = %d, st_y - y = %d\n", x - f->start_x, y - f->start_y);
			//printf("f.z.x = %f\nf.z.y = %f\nit = %f\n\n", f->z.x, f->z.y, it);
			set_color(f, x, y, it);
			x++;
		}
		y++;
	}
	//printf("color = %u\n", f->mv.color);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
