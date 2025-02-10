/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:46:35 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/10 17:38:54 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "limits.h"

#define FLOAT_MIN 1.175494351e-38
#define FLOAT_MAX 3.402823466e+38


int main(int argc, char** argv)
{
    if (argc != 2)
        std::cout << "Bad arg error" << std::endl;
    else
	    ScalarConverter::convert(argv[1]);
	return 0;
}