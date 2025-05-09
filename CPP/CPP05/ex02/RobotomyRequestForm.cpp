/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:07:46 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 16:33:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : 
AForm("RobotomyRequestForm", 72, 45), _target("empty")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): 
AForm("RobotomyRequestForm", 72, 45)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "RobotomyRequestForm named '" << i.getName() << "' sign_grade : " << i.getGradeToSign();
	o << " exec_grade : " << i.getGradeToExec();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void RobotomyRequestForm::act() const
{
	static bool robot = false;

	std::cout << "DRRRRIIIIILLL\nDRRRRIIIIILLL\n";
	if (time(0) % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomization failed" << std::endl;
	robot = !robot;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */