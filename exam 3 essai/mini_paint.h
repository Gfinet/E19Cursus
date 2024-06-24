/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:51:06 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/24 18:19:09 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_circle
{
	char mt_fu;
	float x;
	float y;
	float rad;
	char c;
}	t_circle;

typedef struct s_draw
{
	int w;
	int h;
	char c;
	char **zone;
}	t_draw;