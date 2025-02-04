/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:08:01 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/04 15:08:02 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("No Name"), _gradeToSign(150), _gradeToExec(150)
{
	_checkExec = -1;
	_checkSign = -1;
	_signed = false;
}

Form::Form(std::string Name) : _name(Name), _gradeToSign(150), _gradeToExec(150)
{
	_checkExec = -1;
	_checkSign = -1;
	_signed = false;
}

Form::Form(std::string Name, int grSign) : _name(Name), _checkSign(setGradeToSign(grSign)), _gradeToSign(_checkSign), _gradeToExec(150)
{
	_signed = false;
}

Form::Form(int grSign, int grExec) : _name("No Name"), _checkSign(setGradeToSign(grSign)), _checkExec(setGradeToExec(grExec)),
  _gradeToSign(_checkSign), _gradeToExec(_checkExec)
{
	_signed = false;
}

Form::Form(std::string Name, int grSign, int grExec) : _name(Name), _checkSign(setGradeToSign(grSign)), _checkExec(setGradeToExec(grExec)),
 _gradeToSign(setGradeToSign(grSign)), _gradeToExec(setGradeToExec(grExec))
{
	_signed = false;
}

Form::Form( const Form & src ) : _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &	Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.isSigned();
	}
	(void)rhs;
	return *this;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("You too low  Bro!");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("You too High Bro!");
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat &guy)
{
	try
	{
		if (guy.getGrade() > _gradeToSign)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (guy.getGrade() <= _gradeToSign) // && !_signed)
		_signed = true;
	// else if (_signed)
	// {
	// 	std::cout << _name << " already signed" << std::endl;
	// 	return;
	// }
	if(_signed)
		std::cout << guy.getName() << " signed " << _name << std::endl;
	else
	{
		std::cout << guy.getName() << " couldn't sign " << _name ;
		std::cout << " because he's not graded enough" << std::endl;
	}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

bool Form::isSigned() const
{
	return _signed;
}

std::string Form::getName() const
{
	return _name;
}

int Form::setGradeToExec(int gr)
{
	try
	{
		if (gr < 1)
			throw GradeTooHighException();
		else if (gr > 150)
			throw GradeTooLowException();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	if (!(gr > 0 && gr < 150))
		gr = 150;
	return gr;
}

int Form::setGradeToSign(int gr)
{
	try
	{
		if (gr < 1)
			throw GradeTooHighException();
		else if (gr > 150)
			throw GradeTooLowException();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	if (!(gr > 0 && gr < 150))
		gr = 150;
	return gr;
}


/* ************************************************************************** */