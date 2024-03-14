/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/14 02:21:30 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_circle(t_fract *f)//t_data img, int start_x, int start_y)
{
	int i;
	
	i = 0;
	while (i < COEF * 100)
	{
		my_mlx_pixel_put(&f->img, COEF/2 * sin(i) + f->start_x, COEF/2 * cos(i) + f->start_y, 0x00FFFFFF);
		i++;
	}
}

void draw_axes(t_fract *f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < WIN_WIDTH)
	{
		my_mlx_pixel_put(&(f->img), x, f->start_y , 0x00FFFFFF);
		x++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&(f->img), f->start_x, y, 0x00FFFFFF);
		y++;
	}
}

void set_dec_move(t_fract *f)
{
	if (f->coef < 1000)
	{
		if (f->max_it < 100)
			f->mv.decal = 0.01;
		else if (f->max_it < 500)
			f->mv.decal = 0.05;
		else if (f->max_it < 1000)
			f->mv.decal = 0.1;
		f->mv.move = 10;
		f->mv.zoom = 10;
	}
	else if (f->coef > 1000)
	{
		if (f->max_it < 100)
			f->mv.decal = 0.001;
		else if (f->max_it < 500)
			f->mv.decal = 0.005;
		else if (f->max_it < 1000)
			f->mv.decal = 0.01;
		f->mv.move = 5;
		f->mv.zoom = 100;
	}
}

void set_null(t_fract *f, int j_m)
{
	f->start_x =  WIN_WIDTH / 2;
	f->start_y = WIN_HEIGHT / 2;
	f->coef = WIN_HEIGHT / 1.3;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = -0.8406;//0.390000;
	f->c.y = 0.1242;//0.170000;
	f->mv.color = 7;
	f->mv.b_color = 0;
	f->mv.julia_mandel = j_m;
	set_dec_move(f);
}

t_fract *fract_init(int argc, char **arg)
{
	t_fract *f;

	f = malloc(sizeof(t_fract));
	if (!f)
		return (0);
	if (argc < 3)
		f->max_it = ft_atoi("50");
	else
		f->max_it = ft_atoi(arg[2]);
	set_null(f, ft_atoi(arg[1]));
	f->mlx = mlx_init();
	if (!f->mlx)
		return (esc_handle(f), NULL);
	
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!f->win)
		return (esc_handle(f), NULL);
	f->img.img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img.img)
		return (esc_handle(f), NULL);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
					&f->img.line_length, &f->img.endian);
	if (!f->img.addr)
		return (esc_handle(f), NULL);
	return (f);
}

int	main(int argc, char **argv)
{
	t_fract *f;
	if (argc > 1)
	{
		f = fract_init(argc, argv);
		if (!f)
			return (0);
		draw_fract(f);
		mlx_mouse_hook(f->win, &mouse_event, f);
		mlx_hook(f->win, 17, 0, &esc_handle, f);
		mlx_hook(f->win, 2, 0, &key_event, f);
		mlx_loop(f->mlx);
	}
	else
		print_option();
	return (0);
}

/*

i = 0;
			//printf("c.i : %f\n", f.c.y);
			f->z.x = 0;
			f->z.y = 0;
			while (f->start_x + f->z.x * COEF < WIN_WIDTH &&
				   f->start_y - f->z.y * COEF < WIN_HEIGHT &&
				   i < MAX_IT && f->start_x + f->z.x * COEF > 0 &&
				   f->start_y - f->z.y * COEF > 0 &&
				   mod2(f->z) < 4)
			{
				// printf("mod 2 = %f\n", mod2(f->z));
				//printf("%i (%f,%f) = %X\n", i, f.z.x, f.z.y, 0x00FFFFFF / (i));
				my_mlx_pixel_put(&f->img, f->start_x + f->z.x * COEF, f->start_y - f->z.y * COEF, 0x00AB0606);
				f->z = compute_next(f->z, f->c);
				i++;
			}

*/