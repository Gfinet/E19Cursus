/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:43 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/10 17:30:47 by gfinet           ###   ########.fr       */
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

	sign = - (in[0] == '-');
	for (size_t i = (sign == -1); i < in.length(); i++)
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
	return res;
}

static void printChar(int c)
{
	std::cout << "char   : " ;
	if (!std::isprint(c) || !c)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << (char)c << "'" << std::endl;
	std::cout << "int    : " << c << std::endl;
	std::cout << "float  : " << (float)c << ".0" << std::endl;
	std::cout << "double : " << (double)c << ".0f" << std::endl;
}



void ScalarConverter::convert(std::string a)
{ // char, int, float, double
	e_type x;

	x = getType(a);
	std::cout << x << std::endl;
	// if (x == CHAR)
	// 	printChar(a[0]);
	// else if (x == SPECIAL)
	// 	printSpecial(a);
	// else if (x == INVALID)
	// 	printInvalid();
	// else
	// 	printConvert(getVal(a));

	switch (x)
	{
	case CHAR:
		printChar(a[0]);
		break;
	case SPECIAL:
		printSpecial(a);
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