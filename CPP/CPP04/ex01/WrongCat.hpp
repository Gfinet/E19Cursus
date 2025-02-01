/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:42:32 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:40:39 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

// Class declaration
class WrongCat : public WrongAnimal
{
	private:


	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat();
		
		void makeSound() const;
};

#endif // WRONGCAT_HPP
