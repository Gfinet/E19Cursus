/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/15 16:59:46 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	}
	else if (f->coef > 1000)
	{
		if (f->max_it < 100)
			f->mv.decal = 0.001;
		else if (f->max_it < 500)
			f->mv.decal = 0.005;
		else if (f->max_it < 1000)
			f->mv.decal = 0.01;
	}
}

void	set_null(t_fract *f, int j_m)
{
	f->start_x = WIN_WIDTH / 2;
	f->start_y = WIN_HEIGHT / 2;
	f->coef = 0.003415;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = 0.0;
	f->c.y = 0.0;
	f->mv.follow_m = 1;
	f->mv.color = 10;
	f->mv.b_color = 1;
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
	int		i;
	t_fract	*f;

	f = 0;
	i = 0;
	if (argc > 1 && argc < 4)
	{
		if (argc == 3)
			while (argv[2][i])
				if (!ft_isdigit(argv[2][i++]))
					return (print_option(), 0);
		if (ft_isdigit(argv[1][0]) && !(argv[1][0] > '2'))
			f = fract_init(argc, argv);
		if (!f)
			return (print_option(), 0);
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
