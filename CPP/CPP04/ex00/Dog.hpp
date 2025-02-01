/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:17 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:41:30 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

// Class declaration
class Dog : public Animal
{
	private:

		
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &rhs);
		~Dog();

		void makeSound() const;
};

#endif // DOG_HPP_
