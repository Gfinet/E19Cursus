/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/14 14:30:50 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_dec_move(t_fract *f)
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

void	set_null(t_fract *f, int j_m)
{
	f->start_x = WIN_WIDTH / 2;
	f->start_y = WIN_HEIGHT / 2;
	f->coef = WIN_HEIGHT / 1.3;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = 0.0;
	f->c.y = 0.0;
	f->mv.color = 10;
	f->mv.b_color = 0;
	f->mv.julia_mandel = j_m;
	set_dec_move(f);
}

t_fract	*fract_init(int argc, char **arg)
{
	t_fract	*f;

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
	t_fract	*f;

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
