/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:36 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:41:49 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

// Class declaration
class Animal
{
	private:
	
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal();

		const std::string getType();
		virtual void makeSound() const;
  
};

#endif // ANIMAL_HPP_
