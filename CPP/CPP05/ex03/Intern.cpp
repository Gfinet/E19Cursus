/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:06:46 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 16:37:53 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	_nbFormMade = 0;
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		this->_nbFormMade = rhs._nbFormMade;
	}
	return *this;
}


std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	o << "Just an Intern who made " << i.getNbFormMade() << " forms. ";
	if (i.getNbFormMade() > 10)
		o << "What a great Intern !";
	return o;
}

const char* Intern::NoFormException::what() const throw()
{
	return ("[NorFormException : Name of the Form not knowned!]");
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static AForm* PresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);

}

static AForm* RobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* ShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string Name, std::string target)
{
	std::string form[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
    AForm* (*func[3])(std::string) = {PresidentialForm, RobotomyForm, ShrubberyForm};
	bool found = false;
	try
	{
		for (int i = 0; i < 3; i++)
		{
			found = (form[i] == Name);
			if (found)
			{
				std::cout << "Intern creates " << Name << std::endl;
				return (_nbFormMade++, func[i](target));
			}
		}
		if (!found)
			throw NoFormException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}
	return 0;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Intern::getNbFormMade() const
{
	return _nbFormMade;
}

/* ************************************************************************** */