/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:17 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 17:20:47 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static std::exception GradeTooLowException;
static std::exception GradeTooHighException;

Bureaucrat::Bureaucrat(std::string const Name, int grade) : _Name(Name)
{
	std::exception
	try
	{
		if (grade < 1)
			throw GradeTooHighException;
		else if (grade > 150)
			throw GradeTooLowException;
	}
	catch(const Bureaucrat& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

// Bureaucrat::~Bureaucrat()
// {
// }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}



std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const Bureaucrat::getName() const
{
    return this->_Name;
}

int Bureaucrat::getGrade() const
{
    return this->_Grade;
}

/* ************************************************************************** */