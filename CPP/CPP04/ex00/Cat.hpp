/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:06 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:41:41 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

// Class declaration
class Cat : public Animal
{
	private:


	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &rhs);
		~Cat();
		
		void makeSound() const;
};

#endif // CAT_HPP
