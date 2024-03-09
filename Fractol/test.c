/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:33:51 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/09 17:40:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "inc/fractol.h"
#ifndef WIN_HEIGHT
# define WIN_HEIGHT 1080
#endif
#ifndef WIN_WIDTH
# define WIN_WIDTH 1920
#endif
#ifndef MAX_IT
# define MAX_IT 10
#endif

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


int main()
{
	t_fract *f;
	int i;
	
	i = 0;
	f = malloc(sizeof(t_fract));
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol"); // entre [-2,-1], x [0, 500] - [-1,0], x [500, 1000] 
	f->img.img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
	draw_axes(f->img);
	//draw_circle(*f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_loop(f->mlx);
	free(f);
	return (0);
}