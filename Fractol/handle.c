/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/07 03:32:15 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int esc_handle(int keycode, t_fract *f)
{
	if (keycode == 17)
	{
		mlx_destroy_image(f->mlx, &f->img);
		mlx_destroy_window(f->mlx, f->win);
		mlx_clear_window(f->win, f->mlx);
	}
	return (1);
}

int	key_event(int keycode, t_fract *f)
{
	if (keycode == 65307)
		{esc_handle(17, f);printf("teub\n");}
	printf("Hello from key_hook!\n");
	return (0);
}