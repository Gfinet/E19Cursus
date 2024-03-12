/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/12 16:32:50 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void print_option()
{
	ft_printf("No valid arg provided\n");
	ft_printf("Please try the followings :\n");
	ft_printf("Mandelbrot => ./fractol 1\n");
	ft_printf("Julia => ./fractol 2 R I\n");

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

int	key_event(int keycode, t_fract *f)
{
	if (keycode == 53)
		esc_handle(f);
	printf("Hello from key_hook!\nkey = %d\n", keycode);
	return (0);
}

int mouse_event(int keycode, t_fract *f)
{
	if (keycode == 17)
		esc_handle(f);
	return (1);
}
