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

t_vec	compute_next(t_vec cur, t_vec cons, int burn)
{
	t_vec	res;

	if (!burn)
	{
		res.x = cur.x * cur.x - cur.y * cur.y;
		res.y = 2.0 * cur.x * cur.y;
		res.x += cons.x;
		res.y += cons.y;
	}
	else
	{
		res.x = cur.x * cur.x - cur.y * cur.y;
		res.y = 2.0 * cur.x * cur.y;
		res.x -= cons.x;
		res.y -= cons.y;
	}
	return (res);
}

double	compute_mand(t_fract *f)
{
	double	i;
	t_vec	p;

	i = 0;
	p.x = f->z.x;
	p.y = f->z.y;
	while (p.x * p.x + p.y * p.y < 4.0 && i < f->max_it)
	{
		p = compute_next(p, f->z, 0);
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
	while (p.x * p.x + p.y * p.y < 4.0 && i < f->max_it)
	{
		p = compute_next(p, f->c, 0);
		i++;
	}
	return (i);
}

double	compute_burning(t_fract *f)
{
	double	i;
	t_vec	p;

	i = 0;
	p.x = f->z.x;
	p.y = f->z.y;
	while (p.x * p.x + p.y * p.y < 4.0 && i < f->max_it)
	{
		if (p.x < 0)
			p.x *= -1;
		if (p.y < 0)
			p.y *= -1;
		p = compute_next(p, f->z, 1);
		i++;
	}
	return (i);
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
	mlx_clear_window(f->mlx, f->win);
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			f->z.x = (double)(x - f->start_x) * (f->coef);
			f->z.y = (double)(y - f->start_y) * (f->coef);
			if (f->mv.julia_mandel == 1)
				it = compute_mand(f);
			if (f->mv.julia_mandel == 0)
				it = compute_julia(f);
			else if (f->mv.julia_mandel == 2)
				it = compute_burning(f);
			set_color(f, x, WIN_HEIGHT - y, it);
		}
	}
	printf("%f\n", f->coef);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
