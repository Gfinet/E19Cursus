/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:17 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 19:44:50 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// static std::exception GradeTooLowException(std::string("Too low bro"));
// static std::exception GradeTooHighException("Too High bro");

Bureaucrat::Bureaucrat() : _Name("default")
{
	_Grade = 150;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Not enough High Bro!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too High Bro!");
}

Bureaucrat::Bureaucrat(std::string const Name, int grade) : _Name(Name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	_Grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	if (this != &src)
	{
		_Grade = src.getGrade();
	}
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

int &Bureaucrat::operator++()
{
	if (_Grade > 1)
		_Grade--;
	else
		std::cout << "Grade too high to higher" << std::endl;
    return _Grade;
}

int &Bureaucrat::operator--()
{
	if (_Grade < 150)
		_Grade++;
	else
		std::cout << "Grade too low to lower" << std::endl;
    return _Grade;
}

int Bureaucrat::operator++(int)
{
	int grade = _Grade;
	
	if (_Grade > 1)
		_Grade--;
	else
		std::cout << "Grade too high to higher" << std::endl;
    return grade;
}

int Bureaucrat::operator--(int)
{
	int grade = _Grade;
	
	if (_Grade < 150)
		_Grade++;
	else
		std::cout << "Grade too low to lower" << std::endl;
    return grade;
}

void Bureaucrat::incrGrade()
{
	operator++();
}
void Bureaucrat::decrGrade()
{
	operator--();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if ( this != &rhs )
	{
		// this->_Name = rhs.getName();
		this->_Grade = rhs.getGrade();
	}
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