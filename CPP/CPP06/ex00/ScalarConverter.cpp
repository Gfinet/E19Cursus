/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:43 by Gfinet            #+#    #+#             */
/*   Updated: 2025/03/25 16:25:16 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static void addUp(char c, long double *val)
{
	*val *= 10;
	*val += c - '0';
}

static long double getVal(std::string in)
{
	long double res = 0.0, vir = 0.0;
	int sign, pow=1;
	bool dot = false;

	sign = (in[0] == '-');
	for (size_t i = sign; i < in.length(); i++)
	{
		if (in[i] == '.')
			dot = true;
		if (!dot && isdigit(in[i]))
			addUp(in[i], &res);
		else if (dot && isdigit(in[i]))
		{
			pow *= 10;
			addUp(in[i], &vir);
		}
	}
	vir /= pow;
	res += vir;
	if (sign)
		res *= -1;
	return res;
}

static void printChar(std::string in)
{
	char c = in[0];
	
	if (in.length() == 3)
		c = in[1];
	std::cout << "char   : " ;
	if (!std::isprint(c) || !c)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int    : " << static_cast<int>(c) << std::endl;
	std::cout << "float  : " <<  static_cast<float>(c) << ".0" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0f" << std::endl;
}



void ScalarConverter::convert(std::string a)
{ // special, char, int, float, double, invalid
	e_type x;
	
	x = getType(a);
	//std::cout << x << std::endl;

	switch (x)
	{
	case SPECIAL:
		printSpecial(a);
		break;
	case CHAR:
		printChar(a);
		break;
	case INVALID:
		printInvalid();
		break;
	default:
		printConvert(getVal(a));
		break;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */