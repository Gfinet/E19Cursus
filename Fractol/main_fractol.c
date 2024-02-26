/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/26 19:18:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void *mlx;
	void *win_ptr;
	t_data img;
	int i;
	int start_x;
	int start_y;
	double x;
	double y;
	double ox;
	double oy;
	
	i = 0;
	start_x = 2000/2; // [0,0] = [1000, 625], [-1, 0] = [-500, 625], [0, 1] = [1000, 1125]
	// x = start_x + mandelbrot_x * 500
	// y = start_y + mandelbrot_y * 500

	start_y = 1250/2;
	if (argc > 1)
	{
		ft_printf("%s\n", argv[argc - 1]);
		mlx = mlx_init();
		win_ptr = mlx_new_window(mlx, 2000, 1250, "fractol"); // entre [-2,-1], x [0, 500] - [-1,0], x [500, 1000] 
		img.img = mlx_new_image(mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
		while (i < 11)
		{
			if (i == 0)
			{
				x = 0;
				y = 0;
			}
			else
			{
				x = ox * ox - oy - oy + 0.3;
				y = 2 * ox * oy + 0.3;
				ox = x;
				oy = y;
			}
			printf("%i (%f,", i, x);
			printf("%f)\n", y);
			// printf("%i ",i);
			my_mlx_pixel_put(&img, start_x + x * 500, start_y - y * 500, 0x00FF0000);
			mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
			// if (i < 100)
			// 	my_mlx_pixel_put(&img, 5 + i, start_y, 0x00FF0000);
			// else
			// 	my_mlx_pixel_put(&img, 5 + 100, start_y - 100 + i, 0x00FF0000);
			// mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
			i++;
		}
		//mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
}