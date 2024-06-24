/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:04:25 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/12 22:03:32 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	esc_handle(void *cub)
{
	t_cube *cube;

	cube = cub;
	if (cube)
		mlx_close_window(cube->win);
	exit(0);
}

void	key_event(void *param)
{
	t_cube *cube;

	cube = param;
}

void mouse_event(void *param)
{
	t_cube *cube;

	cube = param;
}