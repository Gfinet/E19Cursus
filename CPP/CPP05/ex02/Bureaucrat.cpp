/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:17 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 18:29:47 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Bureaucrat::Bureaucrat() : _Name("default")
{
	_Grade = 150;
}

Bureaucrat::Bureaucrat(std::string const Name, int grade) : _Name(Name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(int grade) : _Name("default")
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string const Name) : _Name(Name)
{
	_Grade = 150;
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

Bureaucrat::~Bureaucrat()
{
}


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

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Not enough High Bro!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too High Bro!");
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

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

void Bureaucrat::setGrade(int grade)
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
	if (grade > 0 && grade < 150)
		_Grade = grade;
	else
		_Grade = 150;
}

/* ************************************************************************** */