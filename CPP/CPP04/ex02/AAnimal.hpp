/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:36 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 15:25:28 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

// Class declaration
class AAnimal
{
	private:
	
	protected:
		std::string type;
		AAnimal();
	public:
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &rhs);
		virtual ~AAnimal();

		const std::string getType();
		virtual void makeSound();
  
};

#endif // AANIMAL_HPP_
