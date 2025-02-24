/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:07:31 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 18:35:43 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("No Name"), _gradeToSign(150), _gradeToExec(150)
{
	_checkExec = -1;
	_checkSign = -1;
	_signed = false;
}

AForm::AForm(std::string Name) : _name(Name), _gradeToSign(150), _gradeToExec(150)
{
	_checkExec = -1;
	_checkSign = -1;
	_signed = false;
}

AForm::AForm(std::string Name, int grSign) : _name(Name), _checkSign(setGradeToSign(grSign)), _gradeToSign(_checkSign), _gradeToExec(150)
{
	
	_signed = false;
}

AForm::AForm(int grSign, int grExec) : _name("No Name"), _checkSign(setGradeToSign(grSign)), _checkExec(setGradeToExec(grExec)),
  _gradeToSign(_checkSign), _gradeToExec(_checkExec)
{
	_signed = false;
}

AForm::AForm(std::string Name, int grSign, int grExec) : _name(Name), _checkSign(setGradeToSign(grSign)), _checkExec(setGradeToExec(grExec)),
 _gradeToSign(setGradeToSign(grSign)), _gradeToExec(setGradeToExec(grExec))
{
	_signed = false;
}

AForm::AForm( const AForm & src ) : _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &	AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.isSigned();
	}
	(void)rhs;
	return *this;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("[GradeTooLowException : You too low  Bro!]");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("[GradeTooHighException : You too High Bro!]");
}

const char* AForm::NotGradedEnoughException::what() const throw()
{
	return ("[NotGradedEnoughException : You can't do that Bro!]");
}

std::ostream &operator<<(std::ostream &o, AForm const & i)
{
	o << "Form named '" << i.getName() << "' sign_grade : " << i.getGradeToSign();
	o << " exec_grade : " << i.getGradeToExec();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat &guy)
{
	try
	{
		if (guy.getGrade() > _gradeToSign)
			throw NotGradedEnoughException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (guy.getGrade() <= _gradeToSign) // && !_signed)
	{
		_signed = true;
		std::cout << guy.getName() << " signed " << _name << std::endl;
	}
	// else if (_signed)
	// {
	// 	std::cout << _name << " already signed" << std::endl;
	// 	return;
	// }
	else
	{
		std::cout << guy.getName() << " couldn't sign " << _name ;
		std::cout << " because (s)he's not graded enough" << std::endl;
	}

}

void AForm::execute(Bureaucrat const & exec) const
{
	if (!this->isSigned())
	{
		std::cout << "This Form is not signed." << std::endl;
		return ;
	}
	if (exec.getGrade() > this->getGradeToExec())
	{
		std::cout << exec.getName() << " can't execute this task" << std::endl;
		return ;
	}
	this->act();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

bool AForm::isSigned() const
{
	return _signed;
}

std::string AForm::getName() const
{
	return _name;
}

int AForm::setGradeToExec(int gr)
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

int AForm::setGradeToSign(int gr)
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