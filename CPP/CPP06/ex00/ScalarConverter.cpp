/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:43 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/04 18:53:04 by Gfinet           ###   ########.fr       */
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

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


static void printChar(char c)
{
	std::cout << "char   : '" << c << "'" << std::endl;
	std::cout << "int    : " << (int)c << std::endl;
	std::cout << "float  : " << (float)c << std::endl;
	std::cout << "double : " << (double)c << std::endl;
}

static e_type getType(std::string in)
{
	size_t dot = in.find(".");
	size_t f = in.find("f");

	if (in.length() == 1 && isascii(in[0]))
		return CHAR;
	else if (in == "nan" || in == "nanf")
	{

	}
	else if (!(dot == std::string::npos))
	{
		// int
	}
	else if (!(f == std::string::npos))
	{
		//double
	}
	else if()

}

void ScalarConverter::convert(std::string a)
{ // char, int, float, double
	//bool type[4] = {0};
	void *a_void;
	char *c;
	int *i;
	float *f;
	double *d;

	a_void = &a;
	if (a.length() == 1 && isascii((char)a[0]))
		return printChar((char)a[0]);
	else
	{
		get_type();
		c = (char*)(a_void);
		i = (int*)(a_void);
		f = (float*)(a_void);
		d = (double*)(a_void);
		std::cout << "char   : '" << (char)*c << "'" << std::endl;
		std::cout << "int    : " << (int)*i << std::endl;
		std::cout << "float  : " << (float)*f << std::endl;
		std::cout << "double : " << (double)*d << std::endl;
	}
	// c = static_cast<char>(a);
	// i = static_cast<int>(a);
	// f = a;
	// d = a;
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */