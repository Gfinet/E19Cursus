/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:07:36 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/04 15:07:37 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

	class NotGradedEnoughException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

	public:

		AForm();
		AForm(std::string Name);
		AForm(int grSign, int grExec);
		AForm(std::string Name, int grSign);
		AForm(std::string Name, int grSign, int grExec);
		AForm( AForm const & src );
		AForm &operator=( AForm const & rhs );
		virtual ~AForm() = 0;

		virtual void execute(Bureaucrat const & executor) const;
		virtual void act() const = 0;
		void beSigned(Bureaucrat &guy);

		int getGradeToSign() const;
		int getGradeToExec() const;
		bool isSigned() const;
		std::string getName() const;

};

std::ostream &operator<<( std::ostream & o, AForm const & i );


#endif /* ************************************************************ AFORM_H */