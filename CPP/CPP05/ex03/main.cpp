/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/10 20:25:05 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern bob;
    AForm *pres, *shrub, *robot, *tmp;

    pres = bob.makeForm("PresidentialPardonForm", "Been Laten");
    std::cout << *pres << std::endl;
    
    shrub = bob.makeForm("ShrubberyCreationForm", "Shubb");
    std::cout << *shrub << std::endl;

    robot = bob.makeForm("RobotomyRequestForm", "Been Laten (the bad one)");
    std::cout << *robot << std::endl;


    std::cout << bob << std::endl;
    for (int i = 0; i < 10; i++)
    {
        tmp = bob.makeForm("ShrubberyCreationForm", "Shubb");
        delete tmp;
    }
    std::cout << bob << std::endl;
    delete pres;
    delete shrub;
    delete robot;
    return 0;
}