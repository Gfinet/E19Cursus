/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:17 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 15:18:57 by gfinet           ###   ########.fr       */
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

		void makeSound();
};

#endif // DOG_HPP_
