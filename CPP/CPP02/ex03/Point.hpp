/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:20:28 by gfinet            #+#    #+#             */
/*   Updated: 2024/08/20 17:14:47 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "./Fixed.hpp"
# include <iostream>
# include <string>

class Point
{
	private:
		Fixed _x;
		Fixed _y;

	public:

		Point();
		Point(float const x, float const y);
		Point( Point const & src );
		~Point();
		
		Point	&operator=( Point const & rhs );

		Fixed get_x(void) const ;
		Fixed get_y(void) const ;
		void	set_x(float x);
		void	set_y(float y);
		void	set_x(Fixed x);
		void	set_y(Fixed y);
};

#endif