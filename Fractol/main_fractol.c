/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/07 03:30:49 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#ifndef COEF
# define COEF 600
#endif
#ifndef WIN_HEIGHT
# define WIN_HEIGHT 1080
#endif
#ifndef WIN_WIDTH
# define WIN_WIDTH 1920
#endif

//2560 × 1664


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_circle(t_fract f)//t_data img, int start_x, int start_y)
{
	int i;
	
	i = 0;
	while (i < 2500)
	{
		//printf("%f - %f\n",50*sin(i) + start_x, 50 * cos(i) + start_y );
		my_mlx_pixel_put(&f.img, 250*sin(i) + f.start_x, 250 * cos(i) + f.start_y, 0x00FFFFFF);
		i++;
	}
}

void draw_axes(t_data img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < WIN_WIDTH)
	{
		my_mlx_pixel_put(&img, x, WIN_HEIGHT/2 , 0x00FFFFFF);
		x++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&img, WIN_WIDTH/2, y, 0x00FFFFFF);
		y++;
	}
}



int	main(int argc, char **argv)
{
	t_fract f;
	int i;
	
	i = 0;
	f.start_x =  WIN_WIDTH/2 ; // [0,0] = [1000, 625], [-1, 0] = [-500, 625], [0, 1] = [1000, 1125]
	// x = start_x + mandelbrot_x * 500
	// y = start_y + mandelbrot_y * 500

	f.start_y = WIN_HEIGHT/2;
	if (argc)
	{
		ft_printf("%s\n", argv[argc - 1]);
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol"); // entre [-2,-1], x [0, 500] - [-1,0], x [500, 1000] 
		f.img.img = mlx_new_image(f.mlx, WIN_WIDTH, WIN_HEIGHT);
		f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel, &f.img.line_length, &f.img.endian);
		draw_axes(f.img);
		draw_circle(f);//img, start_x, start_y);
		f.c.x = -2;
		while (f.c.x < 1.01)
		{
			
			f.c.y = -1;
			//printf("---c.r : %f---\n", f.c.x);
			while (f.c.y < 1.01)
			{
				i = 1;
				//printf("c.i : %f\n", f.c.y);
				f.z.x = 0;
				f.z.y = 0;
				while (f.start_x + f.z.x * COEF < WIN_WIDTH && f.start_y - f.z.y * COEF < WIN_HEIGHT && i < 5000 &&
				f.start_x + f.z.x * COEF > 0 && f.start_y - f.z.y * COEF > 0)
				{
					//printf("%i (%f,%f) = %X\n", i, f.z.x, f.z.y, 0x00FFFFFF / (i));
					my_mlx_pixel_put(&f.img, f.start_x + f.z.x * COEF, f.start_y - f.z.y * COEF, 0x00AB0606);
					f.z = compute_next(f.z, f.c);
					i++;
				}
				f.c.y += 0.01;
			}
			f.c.x += 0.01;
		}
		mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
		mlx_key_hook(f.win, &key_event, &f);
		mlx_hook(f.win, 17, 0, &esc_handle, &f);
		printf("coucou\n");
		mlx_loop(f.mlx);
		printf("Hello\n");
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