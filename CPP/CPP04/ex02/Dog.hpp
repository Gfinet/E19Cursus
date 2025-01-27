/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:14:17 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 18:05:42 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

// Class declaration
class Dog : public AAnimal
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
		std::string getIdea(int i) const;
};

#endif // DOG_HPP_
