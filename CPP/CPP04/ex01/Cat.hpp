/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:06 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 18:03:08 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

// Class declaration
class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &rhs);
		~Cat();
		
		Brain* getBrain();
		void addIdea(std::string idea);
		void makeSound();
		std::string getIdea(int i) const;
};

#endif // CAT_HPP
