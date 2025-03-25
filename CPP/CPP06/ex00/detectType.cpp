/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:14 by gfinet            #+#    #+#             */
/*   Updated: 2025/03/25 16:24:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(std::string in)
{
	return ((in.length() == 3 && in[0] == in[2] && (in[0] == 39 || in[0] == 34)) \
		|| (in.length() == 1 && !isdigit(in[0]) && isascii(in[0])));
}

static bool isInt(std::string in)
{
	bool sign;

	sign = (in[0] == '+' || in[0] == '-');
	for (size_t i = sign; i < in.length(); i++)
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
	return (in == "nan" || in == "nanf" || in == "+inf" ||
        in == "-inf" || in == "+inff" || in == "-inff");
}

e_type getType(std::string in)
{
	size_t dot = in.find(".");

	//std::cout << "in : " << in << ", len : " << in.length() << ", type : ";
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