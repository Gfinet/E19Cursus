/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:46:24 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 01:27:10 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int _val;
		static int _nbBit;

	public:

		Fixed();
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &operator=( Fixed const & rhs );
		int getRawBits( void ) const;
		void setRawBits( int const raw);


};
#endif