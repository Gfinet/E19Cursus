/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:46:24 by Gfinet            #+#    #+#             */
/*   Updated: 2025/01/13 18:41:39 by Gfinet           ###   ########.fr       */
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
		Fixed(int n);
		Fixed(float n);
		Fixed( Fixed const & src );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		

		Fixed	&operator=( Fixed const & rhs );
		float	operator+(Fixed const &other);
		float	operator-(Fixed const &other);
		float	operator/(Fixed const &other);
		float	operator*(Fixed const &other);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

};

std::ostream &operator<<( std::ostream &o, Fixed const &i );
bool 	operator> (Fixed const &first, Fixed const &other);
bool 	operator< (Fixed const &first, Fixed const &other);
bool 	operator<=(Fixed const &first, Fixed const &other);
bool 	operator>=(Fixed const &first, Fixed const &other);
bool 	operator==(Fixed const &first, Fixed const &other);
bool 	operator!=(Fixed const &first, Fixed const &other);

Fixed min(Fixed const &first, Fixed const &other);
Fixed min(Fixed &first, Fixed &other);
Fixed max(Fixed const &first, Fixed const &other);
Fixed max(Fixed  &first, Fixed  &other);
#endif