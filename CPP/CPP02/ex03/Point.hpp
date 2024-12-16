/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:20:28 by gfinet            #+#    #+#             */
/*   Updated: 2024/12/16 14:21:37 by gfinet           ###   ########.fr       */
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
		Point(Fixed const x, Fixed const y);
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

std::ostream &operator<<( std::ostream &o, Point const &i );

#endif