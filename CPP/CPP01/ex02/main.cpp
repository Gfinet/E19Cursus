/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:48:19 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 15:53:36 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string base = "HI THIS IS BRAIN";
	std::string *stringPTR = &base;
	std::string &stringREF = base;

	std::cout << "[base = ´HI THIS IS BRAIN´] base : " << base << '\n';
	std::cout << "[stringPTR = &base]        PTR  : " << stringPTR << '\n';
	std::cout << "[&stringREF = base]         REF  : " << stringREF << '\n';
	stringREF = *stringPTR;
	std::cout << "[stringREF = *stringPTR;]   REF  : " << stringREF << '\n';

	return (0);
}