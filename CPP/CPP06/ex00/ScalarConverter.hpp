/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:41 by Gfinet            #+#    #+#             */
/*   Updated: 2025/03/25 16:03:01 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>

# ifndef INT32_MIN 
#  define INT32_MIN -2147483648
# endif
# ifndef INT32_MAX
#  define INT32_MAX 2147483647
# endif

enum e_type
{
	SPECIAL = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = 5
};


class ScalarConverter
{

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		virtual ~ScalarConverter() = 0;

		ScalarConverter &operator=( ScalarConverter const & rhs );
		static void convert(std::string a);
		
	private:

};

std::ostream &operator<<( std::ostream & o, ScalarConverter const & i );
e_type getType(std::string in);

void printSpecial(std::string a);
void printInvalid();
void printConvert(long double in);

#endif /* ************************************************* SCALARCONVERTER_H */