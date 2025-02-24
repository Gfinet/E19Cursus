/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 16:18:19 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat b("Jacques", 1);
    std::cout << b << std::endl;
    Bureaucrat a("Jean", 145);
    std::cout << a << std::endl;
    Bureaucrat c("Bob", 150);
    std::cout << c << std::endl;

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
    
    std::cout << std::endl << "---  Testing Hard Contract with grade sign 5, exec 145   ---" << std::endl;
    Form f1("Hard Contract", 5, 15);
    std::cout << f1 << std::endl;
    std::cout << "-- " << c << " try to sign Hard contract --" << std::endl;
    c.signForm(f1);
    std::cout << "-- " << a << " try to sign Hard contract --" << std::endl;
    a.signForm(f1);
    std::cout << "-- " << b << " try to sign Hard contract --" << std::endl;
    b.signForm(f1);
    
    std::cout << std::endl<< "---  Testing Low Contract with grade sign 145            ---" << std::endl;
    Form f2("Low Contract", 145);
    std::cout << f2 << std::endl;
    std::cout << "-- " << c << " try to sign low contract --" << std::endl;
    c.signForm(f2);
    std::cout << "-- " << a << " try to sign low contract --" << std::endl;
    a.signForm(f2);
    std::cout << "-- " << b << " try to sign low contract --" << std::endl;
    b.signForm(f2);
    
    std::cout << std::endl << "---  Testing Bug Contract with grade sign 0              ---" << std::endl;
    Form f3("Bug Contract", 0);
    std::cout << f3 << std::endl;
    b.signForm(f3);
    
    std::cout << std::endl << "---  Testing bug Contract with grade sign 151            ---" << std::endl;
    Form f4("bug contract", 151);
    std::cout << f4 << std::endl;
    b.signForm(f4);

    return 0;
}