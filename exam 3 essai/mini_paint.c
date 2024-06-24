/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:51:02 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/24 18:27:41 by gfinet           ###   ########.fr       */
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
		j = 0;
		while (j < draw->h)
			printf("%c",draw->zone[i][j++]);
		printf("\n");
	}
}

void draw_circle(t_draw *draw, t_circle *circ)
{
	int i = -1, j;

	while (++i < draw->w)
	{
		j = 0;
		while (j < draw->h)
			draw->zone[i][j++] = draw->c;
	}
	i = -1;
	print_circle(draw);
	i += circ->c;
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
	// while (st_line + line_len < 100)
	// {
	// 	st_line = line_len + 1;
	// 	line_len = 0;
	// 	while (buff[st_line + line_len] && buff[st_line + line_len] != '\n' && st_line + line_len < 100)
	// 	{
	// 		line_len++;
	// 	}
	// 	//make_round(&buff[st_line], line_len, buff[st_line] == 'c');
	// }
	//printf("%s\n", buff);
	free_zone(draw.zone, draw.w);
	fclose(fd);
	printf("\n\n");
	return (0);//system("leaks mini"), 0);
}