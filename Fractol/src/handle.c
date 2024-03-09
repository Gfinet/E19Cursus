/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/09 17:08:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int esc_handle(int keycode, t_fract *f)
{
	if (keycode == 17)
	{
		//mlx_destroy_image(f->mlx, &f->img);
		//mlx_clear_window(f->win, f->mlx);
		//mlx_destroy_window(f->mlx, f->win);
	}
	printf("Hello from esc_handle!\n");
	free(f);
	return (1);
}

int	key_event(int keycode, t_fract *f)
{
	if (keycode == 53)
		esc_handle(17, f);
	printf("Hello from key_hook!\n key = %d\n", keycode);
	return (0);
}

int mouse_event(int keycode, t_fract *f)
{
	if (keycode == 17)
		esc_handle(17, f);
	return (1);
}