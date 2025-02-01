/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 18:26:11 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        Bureaucrat a("Bob", 1);
        ShrubberyCreationForm b("test");
        PresidentialPardonForm c("test2");
        RobotomyRequestForm d("test3");

        a.signForm(b);
        b.execute(a);
        a.signForm(c);
        c.execute(a);
        a.signForm(d);
        d.execute(a);
        d.execute(a);
    }
    return 0;
}