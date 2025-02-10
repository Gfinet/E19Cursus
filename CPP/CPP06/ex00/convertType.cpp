/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:27 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/10 17:37:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


static void printChar(long double in)
{
    std::cout << "char   : ";
    if (((long long int)in - in == 0) && (in >= 0 && in <= 127))
    {
        if (isprint(in))
            std::cout << "'" << static_cast<char>(in) << "'";
        else
            std::cout << "Non displayable";
    }
    else
        std::cout << "impossible";
    std::cout << std::endl;
}

static void printInt(long double in)
{
    std::cout << "int    : ";
    if (in < INT32_MIN || in > INT32_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(in) ;
    std::cout << std::endl;
}

static void printDouble(long double in)
{
    std::cout << "double : ";
    if (0)
        std::cout << "impossible";
    else
    {
        std::cout << static_cast<double>(in);
        if ((long long int)in - in == 0)
            std::cout << ".0";
    }
    std::cout << std::endl;
}

static void printFloat(long double in)
{
    std::cout << "float  : ";
    if (0)
        std::cout << "impossible";
    else
    {
        std::cout << static_cast<float>(in) ;
        if ((long long int)in - in == 0)
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;
}

void printSpecial(std::string a)
{
    std::cout << "char   : " << "Impossible" << std::endl;
	std::cout << "int    : " << "Impossible" << std::endl;
    if (a == "nan" || a == "nanf")
    {
        std::cout << "float  : " << "nan" << std::endl;
	    std::cout << "double : " << "nanf" << std::endl;
    }
    else
    {
        std::cout << "float  : " << a[0] << "inf" << std::endl;
	    std::cout << "double : " << a[0] << "inff" << std::endl;
    }
}

void printInvalid()
{
    std::cout << "char   : " << "Impossible" << std::endl;
	std::cout << "int    : " << "Impossible" << std::endl;
	std::cout << "float  : " << "nan" << std::endl;
	std::cout << "double : " << "nanf" << std::endl;
}


void printConvert(long double in)
{
    // char c;
    // int i;
    // double d;
    // float f;

    printChar(in);
    printInt(in);
    printDouble(in);
    printFloat(in);
}