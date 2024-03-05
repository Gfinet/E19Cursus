/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/05 02:03:56 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_circle(t_data img, int start_x, int start_y)
{
	int i;
	
	i = 0;
	while (i < 2500)
	{
		//printf("%f - %f\n",50*sin(i) + start_x, 50 * cos(i) + start_y );
		my_mlx_pixel_put(&img, 250*sin(i) + start_x, 250 * cos(i) + start_y, 0x00FFFFFF);
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
	while (x < 1920)
	{
		my_mlx_pixel_put(&img, x, 1080/2 , 0x00FFFFFF);
		x++;
	}
	while (y < 1080)
	{
		my_mlx_pixel_put(&img, 1920/2, y, 0x00FFFFFF);
		y++;
	}
}



int	main(int argc, char **argv)
{
	void *mlx;
	void *win_ptr;
	t_data img;
	t_data *axes;
	int i;
	int start_x;
	int start_y;
	t_vec c;
	t_vec z;
	
	i = 0;
	start_x = 1920/2; // [0,0] = [1000, 625], [-1, 0] = [-500, 625], [0, 1] = [1000, 1125]
	// x = start_x + mandelbrot_x * 500
	// y = start_y + mandelbrot_y * 500

	start_y = 1080/2;
	axes = malloc(sizeof(t_data));
	if (argc)
	{
		ft_printf("%s\n", argv[argc - 1]);
		mlx = mlx_init();
		win_ptr = mlx_new_window(mlx, 1920, 1080, "fractol"); // entre [-2,-1], x [0, 500] - [-1,0], x [500, 1000] 
		img.img = mlx_new_image(mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		draw_axes(img);
		draw_circle(img, start_x, start_y);
		my_mlx_pixel_put(&img, start_x, start_y, 0x00FFFFFF);
		c.x = -0.5;
		c.y = 0;
		z = c;
		i = 0;
		while (z.x * z.x + z.y *z.y < 4 && i < 200)
		{
			my_mlx_pixel_put(&img, start_x + z.x * 1000, start_y + z.y * 1000, 0xFFFFFFF);
			printf("%i (%f,%f)\n", i, z.x, z.y);
			z = compute_next(z, c);
			i++;
		}
		// printf("%i ",i);
		//printf("%f, %f\n", start_x + x * 500, start_y - y * 500);
		// 	i++;
		mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
		mlx_hook(win_ptr, 17, 0, &esc_handle, mlx);
		mlx_key_hook(win_ptr, &esc_handle, mlx);
		//mlx_destroy_image(mlx,img.img);
		mlx_loop(mlx);
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
*/