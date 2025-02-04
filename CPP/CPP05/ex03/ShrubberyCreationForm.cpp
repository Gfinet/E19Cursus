/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:07:19 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/04 15:07:21 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("ShrubberyCreationForm empty", 145, 137), _target("empty")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : 
AForm("ShrubberyCreationForm", 145, 137)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm named '" << i.getName() << "' sign_grade : " << i.getGradeToSign();
	o << " exec_grade : " << i.getGradeToExec();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::act() const
{
	std::string Name(_target + "_shrubbery");
	std::ofstream newFile(Name.c_str());

	newFile << " ASCII trees inside it AND FUCK YOU." << std::endl;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 12; i++)
		{
			if (i < 9)
			{
				for (int j = 0; j < 20; j++)
				{
					if (j >= 10 - i && j <= 10 + i)
						newFile << "x";
					else
						newFile << " ";
				}
				newFile << std::endl;
			}
			else
			{
				for (int j = 0; j < 20; j++)
				{
					if (j >= 9 && j <= 11)
						newFile << "x";
					else
						newFile << " ";
				}
				newFile << std::endl;
			}
		}
		newFile << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */