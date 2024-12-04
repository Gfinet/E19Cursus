/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:17:29 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/25 17:38:45 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_draw
{
	int w;
	int h;
	char bg;
	char **zone;
}	t_draw;

typedef struct s_square
{
	char r;
	float x;
	float y;
	float w;
	float h;
	char c;
}	t_square;