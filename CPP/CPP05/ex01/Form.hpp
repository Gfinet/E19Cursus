/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:08:03 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/24 15:58:54 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int _checkSign;
		int _checkExec;
		int const _gradeToSign;
		int const _gradeToExec;

	int setGradeToSign(int gr);
	int setGradeToExec(int gr);

	class GradeTooHighException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

	public:

		Form();
		Form(std::string Name);
		Form(int grSign, int grExec);
		Form(std::string Name, int grSign);
		Form(std::string Name, int grSign, int grExec);
		Form( Form const & src );
		~Form();
		Form &		operator=( Form const & rhs );

		void beSigned(Bureaucrat &guy);

		int getGradeToSign() const;
		int getGradeToExec() const;
		bool isSigned() const;
		std::string getName() const;

};

std::ostream &operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */