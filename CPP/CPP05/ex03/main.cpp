/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/03 17:11:01 by gfinet           ###   ########.fr       */
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
    AForm *pres, *shrub, *robot;

    pres = bob.makeForm("PresidentialPardonForm", "Been Laten");
    shrub = bob.makeForm("ShrubberyCreationForm", "Shubb");
    robot = bob.makeForm("RobotomyRequestForm", "Been Laten (the bad one)");

    std::cout << pres << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    return 0;
}