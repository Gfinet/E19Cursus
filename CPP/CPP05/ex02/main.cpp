/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/28 18:31:13 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Jean", 0);
    std::cout << a.getName() << " " << a.getGrade() << std::endl;
    Bureaucrat b("Jacques", 1);
    std::cout << b.getName() << " " << b.getGrade() << std::endl;
    Bureaucrat c("Bob", 150);
    std::cout << c.getName() << " " << c.getGrade() << std::endl;
    Bureaucrat d("Marie", 151);

    // std::cout << d.getGrade() << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;

    // std::cout << "b++ : " << b++ << " " << b << std::endl;
    // std::cout << "b-- : " << b-- << " " << b << std::endl;
    // std::cout << "--b : " << --b << " " << b << std::endl;
    // std::cout << "++b : " << ++b << " " << b << std::endl;    
    // std::cout << "b++ : " << b++ << " " << b << std::endl << std::endl;
    
    // std::cout << "c-- : " << c-- << " " << c << std::endl;
    // std::cout << "c++ : " << c++ << " " << c << std::endl;
    // std::cout << "++c : " << ++c << " " << c << std::endl;    
    // std::cout << "--c : " << --c << " " << c << std::endl;
    // std::cout << "c-- : " << c-- << " " << c << std::endl;
    
    // b.incrGrade();
    // b.decrGrade();

    // c.incrGrade();
    // c.decrGrade();
    
    Form f1("Hard Contract", 5, 15), f2("Low Contract", 145), f3("Bug Contract", 0), f4("bug contract", 151);

    a.signForm(f1);
    a.signForm(f2);
    b.signForm(f1);
    b.signForm(f2);
    b.signForm(f3);
    std::cout << "grade " << f3.getGradeToExec() << " " << f4.getGradeToSign() << std::endl;
    return 0;
}