/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:06 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 16:16:45 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

// Class declaration
class Cat : public AAnimal
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
};

#endif // CAT_HPP
