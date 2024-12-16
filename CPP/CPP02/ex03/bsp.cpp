/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:33:42 by gfinet            #+#    #+#             */
/*   Updated: 2024/12/16 17:51:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Triangle.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (point_in_triangle(Triangle(a,b,c), point));
}