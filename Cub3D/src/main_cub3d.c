/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:40:12 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/29 13:03:19 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int check_format(char *file)
{
	size_t i;

	i = 0;
	while (file && i < ft_strlen(file) && file[i] != '.')
		i++;
	if (ft_strncmp(&file[i], ".cub", 5))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cube cube;

	if (argc != 2 )
		return (write(2, "Error\nBad Arg\n", 14), 0);
	if (!check_format(argv[1]))
		return (write(2, "Error\nBad format\n", 17), 0);
	cube.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "DOOM3D", true);
	mlx_key_hook(cube.mlx, key_event, &cube);
	mlx_close_hook(cube.mlx, esc_handle, &cube);
	mlx_mouse_hook(cube.mlx, mouse_event, &cube);
	mlx_scroll_hook(cube.mlx, scroll_event, &cube);
	mlx_loop_hook(cube.mlx, add_event, &cube);
	write(2, "debug\n", 6);
	mlx_loop(cube.mlx);
	return (0);
}