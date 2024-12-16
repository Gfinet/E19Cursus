/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:46:24 by Gfinet            #+#    #+#             */
/*   Updated: 2024/12/16 17:54:30 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <math.h>

class Fixed
{
	private:
		int _val;
		static int _nbBit;

	public:

		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &operator=( Fixed const & rhs );
		int getRawBits( void ) const;
		void setRawBits( int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream &operator<<( std::ostream &o, Fixed const &i );

#endif