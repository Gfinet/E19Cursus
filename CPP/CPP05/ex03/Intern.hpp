/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:06:53 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/04 15:06:54 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	private:
		unsigned int _nbFormMade;
	public:

		class NoFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &operator=( Intern const & rhs );

		AForm* makeForm(std::string Name, std::string target);
		unsigned int getNbFormMade() const;


};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

// AForm* PresidentialForm(std::string target);
// AForm* RoboteryForm(std::string target);
// AForm* ShrubberyForm(std::string target);

#endif /* ********************************************************** INTERN_H */