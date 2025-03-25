/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:46:35 by Gfinet            #+#    #+#             */
/*   Updated: 2025/03/25 16:35:07 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "limits.h"

#define FLOAT_MIN "1.175494351e-38"
#define FLOAT_MAX 3.402823466e+38
int main()
{

	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("\"");
	std::cout << std::endl;
	ScalarConverter::convert("'");
	std::cout << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("aa");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("\'0\'");
	std::cout << std::endl;
	ScalarConverter::convert("5");
	std::cout << std::endl;
	ScalarConverter::convert("+5");
	std::cout << std::endl;
	ScalarConverter::convert("-5");
	std::cout << std::endl;
	ScalarConverter::convert("-5a");
	std::cout << std::endl;
	ScalarConverter::convert(FLOAT_MIN);
	std::cout << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("5.5");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("55.0f");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;

	return 0;
}