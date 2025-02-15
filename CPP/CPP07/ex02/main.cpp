/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:22:51 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/15 18:09:49 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> a(5), d(5), c(a);
	Array<int> b;

	a[1] = 3;
	std::cout << "a[1] : " << a[1] << std::endl;
	std::cout << "c[1] : " << c[1] << std::endl;
	std::cout << "a[99] : " << a[99] << std::endl;
	std::cout << "b[1] : " << b[1] << std::endl;
	d = a;
	std::cout << "b[1] : " << b[1] << std::endl;

	return 0;
}