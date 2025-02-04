/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:46:35 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/04 18:38:52 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "limits.h"

int main()
{
	std::string intmax(std::to_string(INT_MAX));

	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("5");
	std::cout << std::endl;
	ScalarConverter::convert(intmax);
	std::cout << std::endl;
	ScalarConverter::convert("5.5");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("55.0f");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	std::cout << std::string:: ("5.5");

	return 0;
}