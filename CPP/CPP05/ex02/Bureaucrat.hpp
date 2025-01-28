/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:15 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/28 16:09:39 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat 
{
	private:
		const std::string  _Name;
		int _Grade;

	public:

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		Bureaucrat();
		Bureaucrat(std::string const Name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(std::string const Name);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		void signForm(Form &form); 

		int &operator++();
		int operator++(int);
		int &operator--();
		int operator--(int);
		void incrGrade();
		void decrGrade();
		Bureaucrat &operator=( Bureaucrat const & rhs );
		std::string const getName() const;
		int getGrade() const;
		void setGrade(int grade);

};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */