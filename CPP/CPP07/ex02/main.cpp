/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:22:51 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/18 15:58:57 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define MAX_VAL 750
#include "Array.hpp"
#include <cstdlib>

int main()
{
	{
		Array<int> a(5);
		Array<int> c(a);
		Array<int> b;
		Array<int> d(5);

		a[1] = 3;
		std::cout << "a[1] : " << a[1] << std::endl;
		std::cout << "c[1] : " << c[1] << std::endl;
		std::cout << "a[99] : " << a[99] << std::endl;
		d = a;
		std::cout << "d = a" << std::endl;
		std::cout << "d[1] : " << d[1] << std::endl;
	}
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		std::srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = std::rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete[] mirror;//
		
	}
	return 0;
}
