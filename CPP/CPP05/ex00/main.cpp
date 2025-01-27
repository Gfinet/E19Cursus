/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 20:25:46 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Jean", 0);
    std::cout << a.getGrade() << std::endl;
    Bureaucrat b("Jacques", 1);
    std::cout << b.getGrade() << std::endl;
    Bureaucrat c("Bob", 150);
    std::cout << c.getGrade() << std::endl;
    Bureaucrat d("Marie", 151);

    std::cout << d.getGrade() << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    std::cout << "b++ : " << b++ << " " << b << std::endl;
    std::cout << "b-- : " << b-- << " " << b << std::endl;
    std::cout << "--b : " << --b << " " << b << std::endl;
    std::cout << "++b : " << ++b << " " << b << std::endl;    
    std::cout << "b++ : " << b++ << " " << b << std::endl << std::endl;
    
    std::cout << "c-- : " << c-- << " " << c << std::endl;
    std::cout << "c++ : " << c++ << " " << c << std::endl;
    std::cout << "++c : " << ++c << " " << c << std::endl;    
    std::cout << "--c : " << --c << " " << c << std::endl;
    std::cout << "c-- : " << c-- << " " << c << std::endl;
    
    b.incrGrade();
    b.decrGrade();

    c.incrGrade();
    c.decrGrade();
    
    return 0;
}