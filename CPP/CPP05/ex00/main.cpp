/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 15:51:26 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
    std::cout << "---  Testing Jean with grade 0   ---" << std::endl;
    Bureaucrat a("Jean", 0);
    std::cout << "Grade : " << a.getGrade() << std::endl;
    std::cout << a << std::endl;
    std::cout << "--- Testing Jacques with grade 1 ---" << std::endl;
    Bureaucrat b("Jacques", 1);
    std::cout << "Grade : " << b.getGrade() << std::endl;
    std::cout << b << std::endl;
    std::cout << "---  Testing Bob with grade 150  ---" << std::endl;
    Bureaucrat c("Bob", 150);
    std::cout << "Grade : " << c.getGrade() << std::endl;
    std::cout << c << std::endl;
    std::cout << "---  Testing Marie with grade 151  ---" << std::endl;
    Bureaucrat d("Marie", 151);
    std::cout << "Grade : " << d.getGrade() << std::endl;
    std::cout << d << std::endl << std::endl;

    
    std::cout << "---  Testing incr and decr grade  ---" << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "b++ : ";
    b++;
    std::cout << b << std::endl;
    std::cout << "b-- : ";
    b--;
    std::cout << b << std::endl;
    std::cout << "--b : ";
    --b;
    std::cout << b << std::endl;
    std::cout << "++b : ";
    ++b;
    std::cout << b << std::endl;    
    std::cout << "b++ : ";
    b++;
    std::cout << b << std::endl << std::endl;
    
    std::cout << "c : " << c << std::endl;
    std::cout << "c-- : ";
    c--;
    std::cout << c << std::endl;
    std::cout << "c++ : ";
    c++;
    std::cout << c << std::endl;
    std::cout << "++c : ";
    ++c;
    std::cout << c << std::endl;    
    std::cout << "--c : ";
    --c;
    std::cout << c << std::endl;
    std::cout << "c-- : ";
    c--;
    std::cout << c << std::endl;
    
    b.incrGrade();
    b.decrGrade();

    c.incrGrade();
    c.decrGrade();

    std::cout << std::endl << "--- Testing copy constructor ---" << std::endl;
    std::cout << "e is Jean with grade 45, f and g are 'default'" << std::endl;
    Bureaucrat e("Jean", 45), f, g(f);
    
    std::cout << f << std::endl;
    std::cout << "f = e" << std::endl;
    f = e;
    std::cout << f << std::endl;
    std::cout << "f(e)" << std::endl;
    std::cout << g << std::endl;
    
    return 0;
}