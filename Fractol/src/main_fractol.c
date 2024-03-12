/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/12 13:14:36 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#ifndef COEF
# define COEF 600
#endif
#ifndef WIN_HEIGHT
# define WIN_HEIGHT 1080
#endif
#ifndef WIN_WIDTH
# define WIN_WIDTH 1920
#endif
#ifndef MAX_IT
# define MAX_IT 100
#endif

//2560 × 1664


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
	while (i < 2500)
	{
		my_mlx_pixel_put(&f->img, 250*sin(i) + f->start_x, 250 * cos(i) + f->start_y, 0x00FFFFFF);
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
	while (x < f->start_y)
	{
		my_mlx_pixel_put(&(f->img), x, f->start_y , 0x00FFFFFF);
		x++;
	}
	while (y < f->start_x)
	{
		my_mlx_pixel_put(&(f->img), f->start_x, y, 0x00FFFFFF);
		y++;
	}
}
t_fract *fract_init()
{
	t_fract *f;

	f = malloc(sizeof(t_fract));
	f->start_x =  WIN_WIDTH / 2;
	f->start_y = WIN_HEIGHT / 2;

	f->mlx = mlx_init();
	if (!f->mlx)
		return (NULL);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	// entre [-2,-1], x [0, 500] - [-1,0], x [500, 1000]
	if (!f->win)
		return (esc_handle(f), NULL);
	f->img.img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img.img)
		return (esc_handle(f), NULL);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
					&f->img.line_length, &f->img.endian);
	if (!f->img.addr)
		return (esc_handle(f), NULL);
	draw_axes(f);
	draw_circle(f);
	return (f);
}

void draw_mandelbrot(t_fract *f)
{
	int i;

	i = 0;
	f->c.x = -2;
	while (f->c.x < 1.01)
	{
		f->c.y = -1;
		//printf("---c.r : %f---\n", f.c.x);
		while (f->c.y < 1.01)
		{
			i = 1;
			//printf("c.i : %f\n", f.c.y);
			f->z.x = 0;
			f->z.y = 0;
			while (f->start_x + f->z.x * COEF < WIN_WIDTH && f->start_y - f->z.y * COEF < WIN_HEIGHT && i < MAX_IT &&
			f->start_x + f->z.x * COEF > 0 && f->start_y - f->z.y * COEF > 0)
			{
				//printf("%i (%f,%f) = %X\n", i, f.z.x, f.z.y, 0x00FFFFFF / (i));
				my_mlx_pixel_put(&f->img, f->start_x + f->z.x * COEF, f->start_y - f->z.y * COEF, 0x00AB0606);
				f->z = compute_next(f->z, f->c);
				i++;
			}
			f->c.y += 0.01;
		}
		f->c.x += 0.01;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fract *f;
	
	if (argc)
	{
		ft_printf("%s\n", argv[argc - 1]);
		f = fract_init();
		draw_mandelbrot(f);
		mlx_hook(f->win, 17, 0, &esc_handle, f);
		mlx_key_hook(f->win, &key_event, f);
		mlx_mouse_hook(f->win, &mouse_event, f);
		mlx_loop(f->mlx);
	}
	return (0);
}

/*
		// while (i < 1000)
		// {
		// 	if (i == 0)
		// 	{
		// 		x = 0;
		// 		y = 0;
		// 	}
		// 	else
		// 	{
		// 		x = ox * ox - oy - oy + 0.1;
		// 		y = 2 * ox * oy + 0.2;
		// 		ox = x;
		// 		oy = y;
		// 	}
		// 	printf("%i (%f,", i, x);
		// 	printf("%f)\n", y);
		// 	my_mlx_pixel_put(&img, start_x + x * 500, start_y - y * 500, 0xFFFFFFF);
			// printf("%i ",i);
			//printf("%f, %f\n", start_x + x * 500, start_y - y * 500);
			// if (i < 100)
			// 	my_mlx_pixel_put(&img, 5 + i, start_y, 0x00FF0000);
			// else
			// 	my_mlx_pixel_put(&img, 5 + 100, start_y - 100 + i, 0x00FF0000);
			// mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
		// 	i++;
		// }

		while (i < 500)
		{
			my_mlx_pixel_put(&img, start_x + i, start_y, 0xFFFFFFF);
			i++;
		}
		i=0;
		while (i < 500)
		{
			my_mlx_pixel_put(&img, start_x + 500, start_y + i, 0xFFFFFFF);
			i++;
		}
		i=0;
		while (i < 500)
		{
			my_mlx_pixel_put(&img, start_x + 500 - i, start_y + 500, 0xFFFFFFF);
			i++;
		}
		i=0;
		while (i < 500)
		{
			my_mlx_pixel_put(&img, start_x, start_y + 500 - i, 0xFFFFFFF);
			i++;
		}
		i=0;

				t_color
		{
			0x
			int rouge; 12 
			int rouge; 1200
			int rouge; 120000
		}
*/