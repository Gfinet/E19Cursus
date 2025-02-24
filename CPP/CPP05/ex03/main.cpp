/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 16:37:32 by gfinet           ###   ########.fr       */
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

    pres = bob.makeForm("Presidential Pardon", "Been Laten");
    std::cout << *pres << std::endl;
    
    shrub = bob.makeForm("Shrubbery Creation", "Shubb");
    std::cout << *shrub << std::endl;

    robot = bob.makeForm("Robotomy Request", "Been Laten (the bad one)");
    std::cout << *robot << std::endl;


    std::cout << bob << std::endl;
    for (int i = 0; i < 10; i++)
    {
        tmp = bob.makeForm("Shrubbery Creation", "Shubb");
        delete tmp;
    }
    std::cout << bob << std::endl;
    delete pres;
    delete shrub;
    delete robot;
    return 0;
}