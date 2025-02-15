/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:11:49 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/13 17:38:31 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"
#include <iostream>

int main()
{
	{
		int a(5), b(6);
		char c('a'), d('b');
		float e(5.1), f(6.5);

		std::cout << "a, b : " << a << ", " << b << std::endl; 
		std::cout << "swap int" << std::endl;
		swap(a, b);
		std::cout << "a, b : " << a << ", " << b << std::endl << std::endl;

		std::cout << "c, d : " << c << ", " << d << std::endl; 
		std::cout << "swap char" << std::endl;
		swap(c, d);
		std::cout << "c, d : " << c << ", " << d << std::endl << std::endl;
		
		std::cout << "e, f : " << e << ", " << f << std::endl; 
		std::cout << "swap float" << std::endl;
		swap(e, f);
		std::cout << "e, f : " << e << ", " << f << std::endl << std::endl;

		std::cout << "min (5,6) : " << min<int>(a,b) << std::endl;
		std::cout << "min (a,b) : " << min<char>(c,d) << std::endl;
		std::cout << "min (5.1,6.5) : " << min<float>(e,f) << std::endl;

		std::cout << "max (5,6) : " << max<int>(a,b) << std::endl;
		std::cout << "max (a,b) : " << max<char>(c,d) << std::endl;
		std::cout << "max (5.1,6.5) : " << max<float>(e,f) << std::endl;
		std::cout << std::endl << std::endl;
	}
	{
		int a = 2;
		int b = 3;
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}