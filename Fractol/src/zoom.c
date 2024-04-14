/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:03:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/14 20:55:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	zoom_in(int x, int y, t_fract *f)
{
	f->coef /= 1.1;
	if (f->mv.follow_m)
	{
		f->start_x += (x - f->start_x) * (1 - 1.1);
		f->start_y += (y - f->start_y) * (1 - 1.1);
	}
	else
	{
		f->start_x += (WIN_WIDTH / 2 - f->start_x) * (1 - 1.1);
		f->start_y += (WIN_HEIGHT / 2 - f->start_y) * (1 - 1.1);
	}
}

void	zoom_out(int x, int y, t_fract *f)
{
	f->coef *= 1.1;
	if (f->mv.follow_m)
	{
		f->start_x += (x - f->start_x) * (1 - 1 / 1.1);
		f->start_y += (y - f->start_y) * (1 - 1 / 1.1);
	}
	else
	{
		f->start_x += (WIN_WIDTH / 2 - f->start_x) * (1 - 1 / 1.1);
		f->start_y += (WIN_HEIGHT / 2 - f->start_y) * (1 - 1 / 1.1);
	}
}
