/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:17:26 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/25 19:17:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

void free_zone(char** zone, int len)
{
	int i = -1;
	while (++i < len)
		free(zone[i]);
	free(zone);
}

void print_square(t_draw *draw)
{
	int i = -1, j;

	while (++i < draw->w)
	{
		j = -1;
		while (++j < draw->h)
			write(1, &draw->zone[i][j], 1);
		write(1, "\n", 1);
	}
}
//R 15 15 3 3 #
void draw_square(t_draw *draw, t_square *sq)
{
	int x = -1, y;
	float bt_x, bt_y;

	bt_x = sq->x + sq->w;
	bt_y = sq->y - sq->h;
	while (++x < draw->w)
	{
		y = -1;
		while (++y < draw->h)
			draw->zone[x][y] = draw->bg;
	}
	x = -1;
	while (++x < draw->w)
	{
		y = draw->h;
		while (--y >= 0)
		{
			if (sq->r == 'R')
			{
				if ((y > sq->x - 1 && y < bt_x && x < sq->y + 1 && x > bt_y))
					draw->zone[x][y] = sq->c;
			}
			else
			{
				if (y > sq->x - 1 && y < sq->x +1 && x < sq->y && x > bt_y)
					draw->zone[x][y] = sq->c;
				else if (y > bt_x - 1 && y < bt_x + 1 && x < sq->y && x > bt_y)
					draw->zone[x][y] = sq->c;
				else if (x > sq->y - 1 && x < sq->y + 1 && y > sq->x - 1 && y < bt_x + 1)
					draw->zone[x][y] = sq->c;
				else if (x > bt_y - 1 && x < bt_y + 1 && y > sq->x - 1 && y < bt_x + 1)
					draw->zone[x][y] = sq->c;
			}
		}
	}

	print_square(draw);
}

int main(int argc, char **argv)
{
	int i = -1;
	FILE* fd;
	t_square sq;
	t_draw draw;

	if (argc != 2)
		return (write(1, "Error: argument\n", 16), 1);
	fd = fopen(argv[1], "r");
	if (!fd)
		return (1);
	fscanf(fd, "%d %d %c\n", &draw.w, &draw.h, &draw.bg);
	draw.zone = malloc(sizeof(char *)* draw.w);
	if (!draw.zone)
		return (1);
	while (++i < draw.w)
	{
		draw.zone[i] = malloc(sizeof(char) * draw.h);
		if (!draw.zone[i])
			return (free_zone(draw.zone, i), 1);
	}
	while (fscanf(fd, "%c %f %f %f %f %c\n", &sq.r, &sq.x, &sq.y, &sq.w, &sq.h, &sq.c) != -1)
	{
		printf("r : %c, x : %f, y : %f, w : %f, h : %f, c : %c\n", sq.r, sq.x, sq.y, sq.w, sq.h, sq.c);
		if (sq.w <= 0 || sq.h <= 0 || (sq.r != 'r' && sq.r != 'R'))
			return (1);
		draw_square(&draw, &sq);
	}
	free_zone(draw.zone, draw.w);
	fclose(fd);
	return (0);
}