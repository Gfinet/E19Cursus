/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:17 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 16:16:58 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

// Class declaration
class Dog : public Animal
{
	private:
		Brain* brain;
		
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &rhs);
		~Dog();

		Brain* getBrain();
		void addIdea(std::string idea);
		void makeSound();
};

#endif // DOG_HPP_
