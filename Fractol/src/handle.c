/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/14 02:22:25 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void print_option()
{
	ft_printf("No valid arg provided\n");
	ft_printf("Please try the followings :\n");
	ft_printf("julia => ./fractol 0\n");
	ft_printf("mandelbrot => ./fractol 1\n");

}

int esc_handle(t_fract *f)
{
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->win)
	{
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_window(f->mlx, f->win);
	}
	if (f->mlx)
		free(f->mlx);
	free(f);
	exit(0);
}

void key_event_end(int keycode, t_fract *f)
{
	if (keycode == C)
	{
		f->start_x =  WIN_WIDTH / 2;
		f->start_y = WIN_HEIGHT / 2;
	}
	if (keycode == M)
		f->mv.julia_mandel = 1;
	if (keycode == Z)
		f->mv.julia_mandel = 0;
}	

void key_event_next(int keycode, t_fract *f)
{
	//printf("\nkey = %d\n", keycode);
	if (keycode == ZERO)
		set_null(f, f->mv.julia_mandel);
	if (keycode == L_SH && f->mv.color > 10 && !f->mv.b_color)
		f->mv.color -= 1;
	if (keycode == R_SH && f->mv.color < 1000 && !f->mv.b_color)
		f->mv.color += 1;
	if (keycode == L_SH && f->mv.color > 16 && f->mv.b_color)
		f->mv.color -= 5;
	if (keycode == R_SH && f->mv.color < 1005 && f->mv.b_color)
		f->mv.color += 5;
	if (keycode == I)
		f->z.x += f->mv.decal;
	if (keycode == K)
		f->z.x -= f->mv.decal;
	if (keycode == J)
		f->z.y -= f->mv.decal;
	if (keycode == L)
		f->z.y += f->mv.decal;
	if (keycode == B)
		f->mv.b_color = 1;
	if (keycode == N)
		f->mv.b_color = 0;
	key_event_end(keycode, f);
}

int	key_event(int keycode, t_fract *f)
{
	if (keycode == ESC)
		esc_handle(f);
	else
	{
		set_dec_move(f);
		if (keycode == D)
			f->c.x += f->mv.decal;
		if (keycode == A)
			f->c.x -= f->mv.decal;
		if (keycode == W)
			f->c.y += f->mv.decal;
		if (keycode == S)
			f->c.y -= f->mv.decal;
		if (keycode == RIGHT)
			f->start_x += f->mv.move;
		if (keycode == LEFT)
			f->start_x -= f->mv.move;
		if (keycode == UP)
			f->start_y += f->mv.move;
		if (keycode == DW)
			f->start_y -= f->mv.move;
		key_event_next(keycode, f);
		draw_fract(f);
	}
	return (1);
}

int mouse_event(int mcode, int x, int y, t_fract *f)
{
	int dif_x;
	int dif_y;

	dif_x = f->start_x - x / 2;
	dif_y = f->start_y - y / 2;
	dif_x = (dif_x * (dif_x > 0) - (dif_x * (dif_x < 0)));
	dif_y = (dif_y * (dif_y > 0) - (dif_y * (dif_y < 0)));
	set_dec_move(f);
	if (mcode == 17)
		esc_handle(f);
	if (mcode == M_UP || mcode == M_DW)
	{
		//f->start_x -= dif_x/4;
		//f->start_y -= dif_y;
		//printf("x = %d\ny = %d\n", x, y);
		//f->start_x -= (dif_x * (x > f->start_x)) + (-dif_x * (x < f->start_x));
		//f->start_y -= (dif_y * (y > f->start_y)) + (-dif_y * (y < f->start_y));
		if (mcode == M_UP)
			f->coef += f->mv.zoom;
		if (mcode == M_DW)
			f->coef -= f->mv.zoom;
	}
	draw_fract(f);
	//printf("Hello from mouse!\nkey = %d\n", mcode);
	return (1);
}
