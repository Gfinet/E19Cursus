/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:34:51 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/12 21:28:29 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_vec compute_next(t_vec cur, t_vec cons)
{
	t_vec res;

	res.x = cur.x * cur.x - cur.y * cur.y;//-0.4
	res.y = 2.0 * cur.x * cur.y; //0.3
	res.x += cons.x;
	res.y += cons.y;
	return (res);
}

double mod2(t_vec z)
{
	return (z.x * z.x + z.y * z.y);
}

/*
f->start_x + f->z.x * COEF < WIN_WIDTH &&
		f->start_y - f->z.y * COEF < WIN_HEIGHT &&
		f->start_x + f->z.x * COEF > 0 &&
		f->start_y - f->z.y * COEF > 0 &&
*/

int in_limit(t_fract *f)
{
	if (f->start_x + f->z.x * COEF/2 > WIN_WIDTH ||
		f->start_x + f->z.x * COEF/2 < 0)
		return (0);
	if (f->start_y - f->z.y * COEF/2 + 1 < 0 ||
		f->start_y - f->z.y * COEF/2 + 1 > WIN_HEIGHT)
		return (0);
	return (1);
}

void draw_julia1(t_fract *f)
{
	int i;

	i = 0;
	f->z.x = 0;
	f->z.y = 0;
	while (i < MAX_IT && mod2(f->z) < 4 && in_limit(f))
	{
		//printf("mod 2 = %f\n", mod2(f->z));
		//printf("%i (%f,%f)\n", i, f->start_x + f->z.x * COEF, f->start_y - f->z.y * COEF);
		
		if (i > 50)
			my_mlx_pixel_put(&f->img, f->start_x + f->z.x * COEF/2, f->start_y - f->z.y * COEF/2 + 1, 0x00ffffff);
		f->z = compute_next(f->z, f->c);
		//printf("%i (%f,%f)\n", i, f->z.x, f->z.y);
		i++;
	}
	//printf("i = %d\n",i);
}

int draw_julia(t_fract *f)
{
	int i;

	i = 0;
	f->z.x = 0;
	f->z.y = 0;
	while (i < MAX_IT && mod2(f->z) < 4)
	{
		f->z = compute_next(f->z, f->c);
		i++;
	}
	return (i);
}
void set_color(t_fract *f, t_vec p, int it)
{
	my_mlx_pixel_put(&f->img, p.x, p.y, 0x00FFFFFF/it);
}

// 256/MAX_IT 105906176
void draw_mandelbrot(t_fract *f)
{
	t_vec p;
	int it;
	int x;
	int y;
///////////////////////////////////////////////////
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			p.x = f->start_x + x * COEF/2;
			p.y = f->start_y - y * COEF/2;
			it = draw_julia(f);
			printf("%d %d\n%f %f\n", x, y, p.x, p.y);
			set_color(f, p, it);
			x++;
		}
		y++;
	}
	//ft_printf("coucou\n");
}
void draw_mandelbrot1(t_fract *f)
{
	f->c.x = -2;
	while (f->c.x <= 2)
	{
		f->c.y = -2;
		while (f->c.y <= 2)
		{
			draw_julia(f);
			f->c.y += 0.01;
		}
		f->c.x += 0.01;
	}
}

/*
for (int row = 0; row < height; row++) 
{
    for (int col = 0; col < width; col++) 
	{
        double c_re = (col - width/2.0)*4.0/width;
        double c_im = (row - height/2.0)*4.0/width;
        double x = 0, y = 0;
        int iteration = 0;
        while (x*x+y*y <= 4 && iteration < max) 
		{
            double x_new = x*x - y*y + c_re;
            y = 2*x*y + c_im;
            x = x_new;
            iteration++;
        }
        if (iteration < max) putpixel(col, row, white);
        else putpixel(col, row, black);
    }
}
*/