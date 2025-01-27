/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:15 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 17:19:18 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat 
{
	private:
		const std::string  _Name;
		int _Grade;
		static std::exception GradeTooLowException;
		static std::exception GradeTooHighException;

	public:

		//Bureaucrat();
		Bureaucrat(std::string const Name, int grade);
		Bureaucrat( Bureaucrat const & src );
		// virtual ~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const & rhs );
		std::string const getName() const;
		int getGrade() const;

};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */