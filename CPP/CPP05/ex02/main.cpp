/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/10 20:27:36 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        Bureaucrat A("President", 1);
        Bureaucrat B("Sergeant", 25);
        Bureaucrat C("Police Officer", 137);
        Bureaucrat D("Karen", 146);
        ShrubberyCreationForm b("FUCK");
        PresidentialPardonForm c("Been Laten");
        RobotomyRequestForm d("Been Laten (The bad one)");

        std::cout << D << " try to sign " << b << std::endl;
        D.signForm(b);
        std::cout << D << " try to sign " << c << std::endl;
        D.signForm(c);
        std::cout << D << " try to sign " << d << std::endl;
        D.signForm(d);
        A.signForm(b);

        std::cout << std::endl << std::endl;
        std::cout << C << " try to sign " << c << std::endl;
        C.signForm(c);
        std::cout << C << " try to sign " << d << std::endl;
        C.signForm(d);
        B.signForm(c);

        std::cout << std::endl << std::endl;
        std::cout << B << " try to sign " << d << std::endl;
        B.signForm(d);
        C.signForm(d);
        
        std::cout << std::endl << std::endl;
        b.execute(B);
        c.execute(A);
        d.execute(A);
        d.execute(A);
    }
    {
        std::cout << std::endl << std::endl;
        Bureaucrat A("President", 0);
        Bureaucrat B("Sergeant", 151);
    }
    return 0;
}