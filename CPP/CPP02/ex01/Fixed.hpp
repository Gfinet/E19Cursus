/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:46:24 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 01:44:07 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int _intVal;
		int _floatVal;
		static int _nbBit;

	public:

		Fixed();
		Fixed(int n);
		Fixed(float n);
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