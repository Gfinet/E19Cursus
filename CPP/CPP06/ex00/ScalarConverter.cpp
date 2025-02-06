/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:43 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/06 17:13:34 by Gfinet           ###   ########.fr       */
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

// static bool isAll(int func(int), std::string in)
// {
// 	for (size_t i=0; i < in.length(); i++)
// 	{
// 		if (!func(in.c_str()[0]))
// 			return false;
// 	}
// 	return true;
// }

static void addUp(char c, long double *val)
{
	*val += 10;
	*val += c - '0';
}

static long double getVal(std::string in)
{
	long double res = 0, vir = 0;
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
	vir *= pow;
	res += vir;
	return res;
}

static void printChar(char c)
{
	std::cout << "char   : '" << c << "'" << std::endl;
	std::cout << "int    : " << (int)c << std::endl;
	std::cout << "float  : " << (float)c << std::endl;
	std::cout << "double : " << (double)c << std::endl;
}

static bool isChar(std::string in)
{
	return (in.length() == 1) && isalpha(in[0]);
}

static bool isInt(std::string in)
{
	bool sign;

	sign = (in[0] == '+' || in[0] == '-');
	for (size_t i = sign; i<in.length(); i++)
	{
		if(!isdigit(in[i]))
			return false;
	}
	return true;
}
static bool isFloat(std::string in)
{
	bool sign, dot = false, f = false;

	sign = (in[0] == '+' || in[0] == '-');
	for (size_t i = sign; i < in.length(); i++)
	{
		if ((!isdigit(in[i]) && in[i] != '.' && in[i] != 'f') ||
			(dot && in[i] == '.') || (f && in[i]))
			return false;
		if (in[i] == '.')
			dot = true;
		if(in[i] == 'f')
			f = true;
	}
	return true;
}
static bool isDouble(std::string in)
{
	bool sign, dot = false;

	sign = (in[0] == '+' || in[0] == '-');
	for (size_t i = sign; i < in.length(); i++)
	{
		if ((!isdigit(in[i]) && in[i] != '.')|| (dot && in[i] == '.'))
			return false;
		if (in[i] == '.')
			dot = true;
	}
	return true;
}
static bool isSpecial(std::string in)
{
	return (in == "nan" || in == "nanf" || in == "+inf" || in == "-inf" || in == "+inff" || in == "-inff");
}

static e_type getType(std::string in)
{
	size_t dot = in.find(".");
	// size_t f = in.find("f");

	std::cout << "in : " << in << ", len : " << in.length() << std::endl;
	if (isChar(in))
		return CHAR;
	else if (isSpecial(in))
		return SPECIAL;
	else if (dot != std::string::npos)
	{
		if (isDouble(in))
			return DOUBLE;
		else if (isFloat(in))
			return FLOAT;
	}
	else if (isInt(in))
		return INT;
	return INVALID;

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
	// if (a.length() == 1 && isascii((char)a[0]))
	// 	return printChar((char)a[0]);
	std::cout << getType(a) << std::endl;
	switch (getType(a))
	{
	case 0: //SPECIAL
		//convertSpecial(a);
		break;

	case 1: //char
		printChar(a[0]);
		break;

	case 2: //int
		//convertInt(a);
		break;

	case 3: //float
		//convertFloat(a);
		break;

	case 4: //double
		//convertDouble(a);
		break;

	default: // invalid
		break;
	}
	if (0)
		;
	else
	{
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