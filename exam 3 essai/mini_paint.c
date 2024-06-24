/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:51:02 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/24 21:57:09 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

void free_zone(char **draw, int len)
{
	int i = -1;
	while (++i < len)
		free(draw[i]);
	free(draw);
}

void print_circle(t_draw *draw)
{
	int i = -1, j;

	while (++i < draw->w)
	{
		j=0;
		while (j < draw->h)
			printf("%c ",draw->zone[draw->w - 1 - i][j++]);
		printf("\n");
	}
}

void draw_circle(t_draw *draw, t_circle *circ)
{
	int x = -1, y;

	while (++x < draw->w)
	{
		y = 0;
		while (y < draw->h)
			draw->zone[x][y++] = draw->c;
	}
	// draw->zone[0][0] = '0';
	// draw->zone[draw->w - 1][draw->h - 3] = '1';
	//center = (circ->x, circ->x)
	// srqt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb))
	// distance de point du cercle et centre + 1 < rayon => dans le cercle
	x = -1;
	while (++x < draw->w)
	{
		y = 0;
		while (y < draw->h)
		{
			if (sqrtf((y + 1 - circ->x) * (y + 1 - circ->x) + (x - circ->y) * (x - circ->y)) < circ->rad + 1)
			{
				if (!(sqrtf((y + 1 - circ->x) * (y + 1 - circ->x) + (x - circ->y) * (x - circ->y)) < circ->rad))// pour 'c'
					draw->zone[x][y] = circ->c;
			}
			//printf("(%d, %d)%f\n",x, y, sqrtf((y + 1 - circ->x) * (y + 1 - circ->x) + (x - circ->y) * (x - circ->y)));
			y++;
		}
	}
	print_circle(draw);
	x += circ->c;
}

int main(int argc, char **argv)
{
	FILE *fd;
	int i = -1;
	t_circle circ;
	t_draw draw;
	if (argc != 2)
		return (write(2, "Error: argument\n", 17), 1);
	fd = fopen(argv[1], "r");
	if (!fd)
		return (printf("oh"), 1);
	fscanf(fd, "%d %d %c\n", &draw.w, &draw.h, &draw.c);
	printf("wid : %d, hei : %d, bgc : %c\n", draw.w, draw.h, draw.c);
	if (draw.w > 300 || draw.w < 0 || draw.h > 300 || draw.h < 0)
		return (1);
	draw.zone = malloc(sizeof(char*) * draw.w);
	if (!draw.zone)
		return (1);
	while (++i < draw.w)
	{
		draw.zone[i] = malloc(sizeof(char) * draw.h);
		if (!draw.zone[i])
			return (free_zone(draw.zone, i), 1);
	}
	while (fscanf(fd, "%c %f %f %f %c\n", &circ.mt_fu, &circ.x, &circ.y, &circ.rad, &circ.c) != -1)
	{
		printf("c : %c, X : %f, Y : %f, rad : %f, cic : %c\n", circ.mt_fu, circ.x, circ.y, circ.rad, circ.c);
		draw_circle(&draw, &circ);
	}
	free_zone(draw.zone, draw.w);
	fclose(fd);
	printf("\n\n");
	return (0);//system("leaks mini"), 0);
}